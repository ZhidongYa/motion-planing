#include "AStarPlanner.h"

#include <VirtualRobot/CollisionDetection/CollisionChecker.h>
#include <VirtualRobot/CollisionDetection/CollisionModel.h>



AStarPlanner::AStarPlanner(
        VirtualRobot::RobotPtr robot,
        VirtualRobot::SceneObjectSetPtr obstacles,
        float cellSize)
    : Planner2D(robot, obstacles), cellSize(cellSize)
{
}


float AStarPlanner::heuristic(NodePtr n1, NodePtr n2)
{
    // Compute an optimistic heuristic between n1 and n2.

    ////////////////////////////////////////////////////
    // Enter code here.
    float result = 0;
    ////////////////////////////////////////////////////

    return result;
}


void AStarPlanner::createUniformGrid()
{
    // Initialize nodes.

    // +1 for explicit rounding up
    size_t cols = (sceneBoundsMax.x() - sceneBoundsMin.x()) / cellSize + 1;
    size_t rows = (sceneBoundsMax.y() - sceneBoundsMin.y()) / cellSize + 1;

    for (size_t r = 0; r < rows; r++)
    {
        grid.push_back(std::vector<NodePtr>(cols));
        for (size_t c = 0; c < cols; c++)
        {
            Eigen::Vector2f pos;
            pos.x() = sceneBoundsMin.x() + c * cellSize + cellSize / 2;
            pos.y() = sceneBoundsMin.y() + r * cellSize + cellSize / 2;
            grid[r][c] = std::make_shared<Node>(pos);
        }
    }

    // Initialize valid successors (i.e. add the edges).

    ////////////////////////////////////////////////////
    // Enter code here.
    ////////////////////////////////////////////////////
}


bool AStarPlanner::fulfillsConstraints(NodePtr n)
{
    if (!obstacles)
    {
        return true;
    }
    robotCollisionModel->setGlobalPose(positionToMatrix4f(n->position));

    // Check for collisions.

    ////////////////////////////////////////////////////
    // Enter code here.
    bool fulfillsConstraints = true;
    ////////////////////////////////////////////////////

    return fulfillsConstraints;
}


NodePtr AStarPlanner::closestNode(Eigen::Vector2f v)
{
    size_t r = (v.y() - cellSize / 2 - sceneBoundsMin.y()) / cellSize;
    size_t c = (v.x() - cellSize / 2 - sceneBoundsMin.x()) / cellSize;
    return grid[r][c];
}


std::vector<Eigen::Vector2f> AStarPlanner::plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal)
{
    std::vector<Eigen::Vector2f> result;

    if (!robot || !robot->hasRobotNode(robotColModelName) || !robot->getRobotNode(robotColModelName)->getCollisionModel())
    {
        std::cout << "No collision model with name " << robotColModelName << " found..." << std::endl;
        return result;
    }
    robotCollisionModel = robot->getRobotNode(robotColModelName)->getCollisionModel()->clone();

    grid.clear();
    createUniformGrid();

    NodePtr nodeStart = closestNode(start);
    NodePtr nodeGoal = closestNode(goal);

    std::vector<NodePtr> closedSet;
    std::vector<NodePtr> openSet;
    openSet.push_back(nodeStart);

    std::map<NodePtr, float> gScore;
    gScore[nodeStart] = 0;

    std::map<NodePtr, float> fScore;
    fScore[nodeStart] = gScore[nodeStart] + heuristic(nodeStart, nodeGoal);

    while (!openSet.empty())
    {
        ////////////////////////////////////////////////////
        // Enter code here.
        break;  // ToDo: Remove when done.
        ////////////////////////////////////////////////////
    }

    // Found solution, now retrieve path from goal to start
    if (nodeGoal)
    {
        result = nodeGoal->traversePredecessors();
    }

    // Since the graph was traversed from goal to start, we have to reverse the order.
    std::reverse(result.begin(), result.end());

    return result;
}
