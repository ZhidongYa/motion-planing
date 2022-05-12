#pragma once

#include "Planner2D.h"
#include "Node.h"

/**
 * An RRT planner.
 */
class RRTPlanner : public Planner2D
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    RRTPlanner(VirtualRobot::RobotPtr robot,
               VirtualRobot::SceneObjectSetPtr obstacles = {},
               float goalReachedEpsilon = 200.0f,
               float incrementalDistance = 50.f,
               float randomNodeGoal = 0.01f);


    std::vector<Eigen::Vector2f> plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal);


private:

    /// Create a random real number in the range [0,1)
    float randomFloat();

    NodePtr createRandomNode(NodePtr nodeGoal, float randomNodeGoal);
    NodePtr nearestVertex(NodePtr nodeRandom);
    NodePtr extend(NodePtr nodeNear, NodePtr nodeRandom, float incrementalDistance);
    bool fulfillsConstraints(NodePtr nodeNew);
    void addVertex(NodePtr nodeNew);
    void addEdge(NodePtr nodeNear, NodePtr nodeNew);


private:

    /// How close the robot should be to the goal.
    float goalReachedEpsilon;
    /// How far a node is extended in each iteration.
    float incrementalDistance;
    /// A small chance to select the goal when creating a random node.
    float randomNodeGoal;

    std::vector<NodePtr> vertices;

};


