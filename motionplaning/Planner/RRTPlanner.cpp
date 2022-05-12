#include "RRTPlanner.h"

#include <cstdlib>

#include <VirtualRobot/CollisionDetection/CollisionChecker.h>
#include <VirtualRobot/CollisionDetection/CollisionModel.h>


RRTPlanner::RRTPlanner(
        VirtualRobot::RobotPtr robot,
        VirtualRobot::SceneObjectSetPtr obstacles,
        float goalReachedEpsilon,
        float incrementalDistance,
        float randomNodeGoal)
    : Planner2D(robot, obstacles),
      goalReachedEpsilon(goalReachedEpsilon),
      incrementalDistance(incrementalDistance),
      randomNodeGoal(randomNodeGoal)
{
    srand(time(nullptr));
}


float RRTPlanner::randomFloat()
{
    return static_cast<float>(rand() / RAND_MAX);
}


NodePtr RRTPlanner::createRandomNode(NodePtr nodeGoal, float randomNodeGoal)
{
    // With a chance of `randomNodeGoal`, try targeting the goal node.
    if (randomFloat() < randomNodeGoal)
    {
        return nodeGoal;
    }
    else
    {
        Eigen::Vector2f resultPos;
        resultPos.x() = sceneBoundsMin.x() + (sceneBoundsMax.x() - sceneBoundsMin.x()) * randomFloat();
        resultPos.y() = sceneBoundsMin.y() + (sceneBoundsMax.y() - sceneBoundsMin.y()) * randomFloat();
        return std::make_shared<Node>(resultPos);
    }
}


NodePtr RRTPlanner::nearestVertex(NodePtr nodeRandom)
{
    if (vertices.empty())
    {
        return nullptr;
    }

    NodePtr nearest = vertices[0];

    ////////////////////////////////////////////////////
    // Enter code here.
    ////////////////////////////////////////////////////

    return nearest;
}


NodePtr RRTPlanner::extend(NodePtr nodeNear, NodePtr nodeRandom, float incrementalDistance)
{
    Eigen::Vector2f newPos = Eigen::Vector2f::Zero();

    ////////////////////////////////////////////////////
    // Enter code here.
    ////////////////////////////////////////////////////

    return std::make_shared<Node>(newPos);
}


bool RRTPlanner::fulfillsConstraints(NodePtr nodeNew)
{
    if (!obstacles)
    {
        return true;
    }

    robotCollisionModel->setGlobalPose(positionToMatrix4f(nodeNew->position));

    ////////////////////////////////////////////////////
    // Enter code here.
    // Hint: Collision checking between obstacle i and the robot model, can be done with the following line:
    // float dist = VirtualRobot::CollisionChecker::getGlobalCollisionChecker()->calculateDistance(
    // robotCollisionModel, obstacles->getSceneObject(i)->getCollisionModel());
    bool fulfillsConstraint = true;
    ////////////////////////////////////////////////////

    return fulfillsConstraint;
}


void RRTPlanner::addVertex(NodePtr nodeNew)
{
    vertices.push_back(nodeNew);
}


void RRTPlanner::addEdge(NodePtr nodeNear, NodePtr nodeNew)
{
    nodeNew->predecessor = nodeNear;
    nodeNear->successors.push_back(nodeNew);
}


std::vector<Eigen::Vector2f> RRTPlanner::plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal)
{
    std::vector<Eigen::Vector2f> result;

    if (!robot || !robot->hasRobotNode(robotColModelName) || !robot->getRobotNode(robotColModelName)->getCollisionModel())
    {
        std::cout << "No collision model with name " << robotColModelName << " found..." << std::endl;
        return result;
    }
    robotCollisionModel = robot->getRobotNode(robotColModelName)->getCollisionModel()->clone();

    vertices.clear();
    addVertex(std::make_shared<Node>(start));

    NodePtr nodeGoal = std::make_shared<Node>(goal);

    int step = 0;
    bool foundSolution = false;
    while (!foundSolution)
    {
        step++;
        if (step > 10000)
        {
            std::cout << "step > 10000, aborting..." << std::endl;
            return result;
        }

        ////////////////////////////////////////////////////
        // Enter code here.
        ////////////////////////////////////////////////////
    }

    // Found solution, now retrieve path from goal to start.
    if (nodeGoal)
    {
        result = nodeGoal->traversePredecessors();
    }

    // Since the graph was traversed from goal to start, we have to reverse the order.
    std::reverse(result.begin(), result.end());

    return result;
}

