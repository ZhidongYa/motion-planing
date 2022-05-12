#pragma once

#include <VirtualRobot/SceneObjectSet.h>
#include <VirtualRobot/SceneObject.h>
#include <VirtualRobot/Robot.h>
#include <Eigen/Geometry>


class Planner2D
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    /**
     * Initialize Planner with robot and obstacles.
     * @param robot The robot
     * @param obstacles The obstacles which should be considered by the planner
    */
    Planner2D(VirtualRobot::RobotPtr robot, VirtualRobot::SceneObjectSetPtr obstacles = VirtualRobot::SceneObjectSetPtr());


    // Planners implement this method.
    virtual std::vector<Eigen::Vector2f> plan(const Eigen::Vector2f& start, const Eigen::Vector2f& goal) = 0;


    /// Update obstacles.
    void setObstacles(VirtualRobot::SceneObjectSetPtr obstacles);

    /// Update robot.
    void setRobot(VirtualRobot::RobotPtr robot);

    /// Set name of RobotNode which should be used for collision detection.
    void setRobotColModel(const std::string &robotColModelName);

    Eigen::Matrix4f positionToMatrix4f(const Eigen::Vector2f& pos);

    /// Set a float parameter that is identified with a string.
    void setParameter(const std::string &s, float p);

    /// Check if a parameter is set.
    bool hasParameter(const std::string &s);

    /// Get the corresponding float parameter (0 is returned when parameter string is not present).
    float getParameter(const std::string &s);


    struct Point2D
    {
        Eigen::Vector2f pos;
        Eigen::Vector2f dir;
    };

    virtual std::vector<Point2D> getGridVisu(float xdist, float ydist, Eigen::Vector2f goal)
    {
        return {};
    }

protected:

    std::string robotColModelName;

    /// Local copy of the robot's collision model that can be moved around without moving the robot
    VirtualRobot::CollisionModelPtr robotCollisionModel;
    VirtualRobot::RobotPtr robot;
    VirtualRobot::SceneObjectSetPtr obstacles;

    Eigen::Vector2f sceneBoundsMin;
    Eigen::Vector2f sceneBoundsMax;

    std::map<std::string, float> parameters;
};

using Planner2DPtr = std::shared_ptr<Planner2D>;


