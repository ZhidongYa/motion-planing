#include "PFPlanner.h"

#include <VirtualRobot/CollisionDetection/CollisionChecker.h>
#include <VirtualRobot/CollisionDetection/CollisionModel.h>


PFPlanner::PFPlanner(
        VirtualRobot::RobotPtr robot,
        VirtualRobot::SceneObjectSetPtr obstacles,
        float goalReachedEpsilon,
        float cAtt,
        float cRep,
        float cAreaOfInfluence)
    : Planner2D(robot, obstacles),
      goalReachedEpsilon(goalReachedEpsilon),
      cAtt(cAtt),
      cRep(cRep),
      cAreaOfInfluence(cAreaOfInfluence)
{
}


Eigen::Vector2f PFPlanner::calcAttractingForce(Eigen::Vector2f currentPosition, Eigen::Vector2f goal)
{
    ////////////////////////////////////////////////////
    // Enter code here.
    // Hint: Input positions are millimeters, but formula works in meters.

    Eigen::Vector2f result = Eigen::Vector2f::Zero();
    result= -cAtt*(currentPosition-goal);


    ////////////////////////////////////////////////////

    return result;
}


Eigen::Vector2f PFPlanner::calcRepulsiveForce(Eigen::Vector2f currentPosition, VirtualRobot::SceneObjectPtr obstacle)
{
    Eigen::Vector2f result = Eigen::Vector2f::Zero();
    if (!robotCollisionModel || !obstacle)
    {
        return result;
    }
    robotCollisionModel->setGlobalPose(positionToMatrix4f(currentPosition));

    ////////////////////////////////////////////////////
    // Enter code here.
    /* Hint #1: Do find out how to calculate the shortest distance between two scene objects
     *   (robot and obstacle), consult Section 2.4 in the Simox document (SoftwareH2T.pdf).
     * Hint #2: The formula for repulsive potential works best when you use meters (not millimeters).
     */
    ////////////////////////////////////////////////////
     Eigen::Vector3f P1;
    P1<<currentPosition(0),currentPosition(1),0;
    Eigen::Vector3f P2 = obstacle->getGlobalPosition();
    //Eigen::Vector3f surface1,surface2;
    int id1,id2;

    float cAreaOfInfluence = this->cAreaOfInfluence/1000.0;
    float distance= VirtualRobot::CollisionChecker::getGlobalCollisionChecker()->calculateDistance(
                robotCollisionModel, obstacle->getCollisionModel(), P1, P2, &id1, &id2);
    distance = distance/1000.0;
    if( distance <= 0){return result;}
    else if(	distance < cAreaOfInfluence){
        result = -cRep*(1/distance-1/cAreaOfInfluence)* 1/(distance*distance)* (P1-P2).head(2)/distance;
        }
    else {
        result;
    }

    return result;
}


std::vector<Eigen::Vector2f> PFPlanner::plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal)
{
    // Each step should be at maximum this far.
    const float maxStep = 100.0f;
    const float minStep = 60.0f;

    std::vector<Eigen::Vector2f> result;
    if (!robot || !robot->hasRobotNode(robotColModelName) || !robot->getRobotNode(robotColModelName)->getCollisionModel())
    {
        std::cout << "No collision model with name " << robotColModelName << " found..." << std::endl;
        return result;
    }
    robotCollisionModel = robot->getRobotNode(robotColModelName)->getCollisionModel()->clone();

    Eigen::Vector2f iterationPosition = start;
    result.push_back(iterationPosition);

    int loop = 0;
    while ((iterationPosition - goal).norm() > goalReachedEpsilon)
    {
        
        Eigen::Vector2f forceAttracting = calcAttractingForce(iterationPosition, goal);
       Eigen::Vector2f forceRepulsive = Eigen::Vector2f::Zero();
       Eigen::Vector2f forceSum = Eigen::Vector2f::Zero();
       Eigen::Vector2f forceDir = Eigen::Vector2f::Zero();
       if (obstacles)
       {
           for (size_t i = 0; i < obstacles->getSize(); i++)
           {
               forceRepulsive += calcRepulsiveForce(iterationPosition, obstacles->getSceneObject(i));
           }
       }
       forceSum = forceAttracting + forceRepulsive;
       if(forceSum.norm()<=minStep){
           iterationPosition += Eigen::VectorXf::Random(2)*50;
       }
       else{
       forceDir = forceSum/forceSum.norm();
       if(forceSum.norm()>=maxStep) {iterationPosition+=forceDir*maxStep;}
       else{iterationPosition+=forceSum;}
       }
       result.push_back(iterationPosition);
        if (loop > 1000)
        {
            std::cout << "loop > 1000, breaking" << std::endl;
            return result;
        }
        loop++;
    }

    return result;
}


std::vector<Planner2D::Point2D> PFPlanner::getGridVisu(float xdist, float ydist, Eigen::Vector2f goal)
{
    // Used to visualize the potential field.

    robotCollisionModel = robot->getRobotNode(robotColModelName)->getCollisionModel()->clone();

    std::vector<Point2D> result;
    for (float x = sceneBoundsMin.x(); x < sceneBoundsMax.x(); x += xdist)
    {
        for (float y = sceneBoundsMin.y(); y < sceneBoundsMax.y(); y += ydist)
        {
            Eigen::Vector2f pos = {x, y};
            Eigen::Vector2f forceAttracting = calcAttractingForce(pos, goal);

            Eigen::Vector2f forceRepulsive = Eigen::Vector2f::Zero();
            if (obstacles)
            {
                for (size_t i = 0; i < obstacles->getSize(); i++)
                {
                    forceRepulsive += calcRepulsiveForce(pos, obstacles->getSceneObject(i));
                }
            }
            Eigen::Vector2f forceSum = forceAttracting + forceRepulsive;

            Point2D& p = result.emplace_back();
            p.pos = pos;
            p.dir = forceSum;
        }
    }

    return result;
}
