#pragma once

#include <boost/shared_ptr.hpp>
#include <Eigen/Geometry>
#include <vector>
#include <VirtualRobot/VirtualRobot.h>


class Node;
using NodePtr = std::shared_ptr<Node>;


/**
 * A Node can store data to all valid neighbors (successors) and a precessor.
 * It offers methods to determine the complete path to the starting point.
 */
class Node
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    Node(Eigen::Vector2f position);

    Eigen::Vector2f position;
    /// All nodes that are adjacent to this one.
    std::vector<NodePtr> successors;
    /// For traversal.
    NodePtr predecessor;

    /// Collects all predecessors in order to generate path to starting point.
    std::vector<Eigen::Vector2f> traversePredecessors();

};
