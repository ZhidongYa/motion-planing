#pragma once

#include <string>
#include <vector>

#include <VirtualRobot/VirtualRobot.h>
#include <VirtualRobot/Obstacle.h>
#include <VirtualRobot/Robot.h>
#include <VirtualRobot/RobotNodeSet.h>
#include <VirtualRobot/VirtualRobotException.h>
#include <VirtualRobot/Nodes/RobotNode.h>
#include <VirtualRobot/Visualization/VisualizationFactory.h>
#include <VirtualRobot/Visualization/CoinVisualization/CoinVisualizationNode.h>
#include <VirtualRobot/Visualization/CoinVisualization/CoinVisualization.h>
#include <VirtualRobot/XML/RobotIO.h>

#include <QtCore/QtCore>
#include <QtCore/QtGlobal>
#include <QtGui/QtGui>

#include <Inventor/sensors/SoTimerSensor.h>
#include <Inventor/nodes/SoEventCallback.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/nodes/SoSeparator.h>

#include "Planner/Planner2D.h"

#include "ui_PathPlanning.h"


class PathPlanningWindow : public QMainWindow
{
    Q_OBJECT
public:

    PathPlanningWindow();
    ~PathPlanningWindow();

    /// Executes the SoQt mainLoop. You need to call this in order to execute the application.
    int main();

    bool loadRobot(std::string robotFilename);


public slots:

    /// Closes the window and exits SoQt runloop.
    void quit();

    /// Overriding the close event, so we know when the window was closed by the user.
    void closeEvent(QCloseEvent* event);

    void resetSceneryAll();

    void loadScene(std::string sceneFile);

    void checkBoxOption1();

    void buttonRunPlanner();
    void visualizeGrid();
    void buttonStep2();
    void buttonStep3();

    void sliderTrajectory(int pos);

    void comboBoxSelectScene(int scene);
    void comboBoxSelectAlgorithm(int algo);
    void rebuildVisualization();


protected:

    void setupUI();

    void showTrajectory(std::vector< Eigen::Vector2f > &traj);


    std::string robotFilename;
    Ui::PathPlanning UI;
    SoQtExaminerViewer* viewer; ///< Viewer to display the 3D model of the robot and the environment.

    SoSeparator* sceneSep;
    SoSeparator* robotSep;
    SoSeparator* obstacleSep;
    SoSeparator* floorSep;
    SoSeparator* trajectorySep;
    SoSeparator* gridSep;

    Planner2DPtr planner;
    VirtualRobot::SceneObjectSetPtr obstacles;
    VirtualRobot::SceneObjectPtr floor;

    VirtualRobot::RobotPtr robot;
    VirtualRobot::ScenePtr scene;
    std::vector<std::string> sceneFiles;

    std::vector<Eigen::Vector2f> trajectory;

    VirtualRobot::CoinVisualizationPtr visualization;


    struct Parameters
    {
        Eigen::Vector2f goal = {2500, 9000};

        struct Common
        {
            float goalReachedEpsilon = 100.0f;
        };
        Common common;

        struct PfPlanner
        {
            float cAtt = 1000.f;
            float cRep = 500.0f;
            float cAreaOfInfluence = 300.0f;
        };
        PfPlanner pf;

        struct RrtPlanner
        {
            float incrementalDistance = 50.f;
            float randomNodeGoal = 0.5f;
        };
        RrtPlanner rrt;

        struct AStar
        {
            float cellSize = 100;
        };
        AStar astar;
    };
    Parameters params;

};
