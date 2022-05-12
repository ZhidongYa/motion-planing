#pragma once

#include "Planner2D.h"


class PFPlanner : public Planner2D
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    PFPlanner(VirtualRobot::RobotPtr robot,
              VirtualRobot::SceneObjectSetPtr obstacles = {},
              float goalReachedEpsilon = 100.0f,
              float cAtt = 1.0f,
              float cRep = 10.0f,
              float cAreaOfInfluence = 500.0f);

    std::vector<Eigen::Vector2f> plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal);

    std::vector<Point2D> getGridVisu(float xdist, float ydist, Eigen::Vector2f goal);


private:

    Eigen::Vector2f calcAttractingForce(Eigen::Vector2f currentPosition, Eigen::Vector2f goal);
    Eigen::Vector2f calcRepulsiveForce(Eigen::Vector2f currentPosition, VirtualRobot::SceneObjectPtr obstacle);


private:

    float goalReachedEpsilon;
    /// Constant for the attracting force.
    float cAtt;
    /// Constant for the repulsive force.
    float cRep;
    /// How far an obstacle emits a repulsive.
    float cAreaOfInfluence;

};
