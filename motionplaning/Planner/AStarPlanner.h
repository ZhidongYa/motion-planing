#pragma once

#include "Planner2D.h"
#include "Node.h"

/**
 * The A* planner
 */
class AStarPlanner : public Planner2D
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    AStarPlanner(VirtualRobot::RobotPtr robot,
                 VirtualRobot::SceneObjectSetPtr obstacles = {},
                 float cellSize = 100.f);


    std::vector<Eigen::Vector2f> plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal);


private:

    float heuristic(NodePtr n1, NodePtr n2);
    void createUniformGrid();
    bool fulfillsConstraints(NodePtr n);
    NodePtr closestNode(Eigen::Vector2f v);


private:

    /// How big each cell is in the uniform grid.
    float cellSize;

    std::vector<std::vector<NodePtr> > grid;

};


