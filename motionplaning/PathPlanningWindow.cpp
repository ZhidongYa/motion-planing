
#include "PathPlanningWindow.h"
#include "Planner/PFPlanner.h"
#include "Planner/RRTPlanner.h"
#include "Planner/AStarPlanner.h"

#include <SimoxUtility/color.h>
#include <SimoxUtility/math/pose.h>
#include <SimoxUtility/math/convert/rad_to_deg.h>

#include <VirtualRobot/RuntimeEnvironment.h>
#include <VirtualRobot/XML/SceneIO.h>

#include <Eigen/Geometry>

#include <cmath>
#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>

#include <Inventor/nodes/SoShapeHints.h>
#include <Inventor/nodes/SoLightModel.h>
#include <Inventor/nodes/SoCube.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoUnits.h>
#include <Inventor/actions/SoLineHighlightRenderAction.h>


using namespace VirtualRobot;

float TIMER_MS = 30.0f;


PathPlanningWindow::PathPlanningWindow() : QMainWindow(nullptr)
{
    VR_INFO << " start " << std::endl;
    robotFilename = "robots/ArmarIII/ArmarIII.xml";
    VirtualRobot::RuntimeEnvironment::getDataFileAbsolute(robotFilename);

    sceneSep = new SoSeparator;
    sceneSep->ref();
    robotSep = new SoSeparator;
    sceneSep->addChild(robotSep);
    obstacleSep = new SoSeparator;
    sceneSep->addChild(obstacleSep);
    floorSep = new SoSeparator;
    sceneSep->addChild(floorSep);
    trajectorySep = new SoSeparator;
    sceneSep->addChild(trajectorySep);

    gridSep = new SoSeparator;
    sceneSep->addChild(gridSep);

    setupUI();

    std::string sceneFile1(DEMO_BASE_DIR "/data/PathPlanningScene1.xml");
    std::string sceneFile2(DEMO_BASE_DIR "/data/PathPlanningScene2.xml");
    std::string sceneFile3(DEMO_BASE_DIR "/data/PathPlanningScene3.xml");
    sceneFiles.push_back(sceneFile1);
    sceneFiles.push_back(sceneFile2);
    sceneFiles.push_back(sceneFile3);

    // Setup box scene
    UI.comboBoxScene->setCurrentIndex(1);
    comboBoxSelectScene(1);

    // Setup pf planner
    UI.comboBoxAlgo->setCurrentIndex(2);
    comboBoxSelectAlgorithm(2);

    viewer->viewAll();
}

bool PathPlanningWindow::loadRobot(std::string robotFilename)
{
    std::cout << "Loading Robot from " << robotFilename << std::endl;

    try
    {
        robot = RobotIO::loadRobot(robotFilename,RobotIO::eFull);
    }
    catch (VirtualRobotException &e)
    {
        std::cout << " ERROR while creating robot" << std::endl;
        std::cout << e.what();
        return false;
    }

    if (!robot)
    {
        std::cout << " ERROR while creating robot" << std::endl;
        return false;
    }

    try
    {
        VirtualRobot::BoundingBox bbox = robot->getBoundingBox();

        Eigen::Matrix4f gp = Eigen::Matrix4f::Identity();
        //gp(2,3) = 5.0f;
        gp(2,3) = -bbox.getMin()(2) + 4.0f;
        gp(0,3) = 2500;
        gp(1,3) = 1000;
        robot->setGlobalPose(gp);
    }
    catch (VirtualRobotException &e)
    {
        std::cout << " ERROR while building dynamic robot" << std::endl;
        std::cout << e.what();
        return false;
    }

    return true;
}


PathPlanningWindow::~PathPlanningWindow()
{
    robot.reset();
    sceneSep->unref();
}

void PathPlanningWindow::setupUI()
{
    UI.setupUi(this);
    //centralWidget()->setLayout(UI.gridLayoutViewer);
    viewer = new SoQtExaminerViewer(UI.frameViewer, "", TRUE, SoQtExaminerViewer::BUILD_POPUP);

    // setup
    viewer->setBackgroundColor(SbColor(1.0f, 1.0f, 1.0f));
    viewer->setAccumulationBuffer(false);
    viewer->setAntialiasing(true, 4);

    viewer->setGLRenderAction(new SoLineHighlightRenderAction);
    viewer->setTransparencyType(SoGLRenderAction::BLEND);
    viewer->setFeedbackVisibility(true);
    viewer->setSceneGraph(sceneSep);

    viewer->setAccumulationBuffer(false);
    viewer->setAntialiasing(true, 4);

    viewer->viewAll();

    connect(UI.pushButtonReset, SIGNAL(clicked()), this, SLOT(resetSceneryAll()));
    connect(UI.pushButtonRunPlanner, SIGNAL(clicked()), this, SLOT(buttonRunPlanner()));
    connect(UI.visualizeGridButton, SIGNAL(clicked()), this, SLOT(visualizeGrid()));
    connect(UI.pushButtonStep2, SIGNAL(clicked()), this, SLOT(buttonStep2()));
    connect(UI.pushButtonStep3, SIGNAL(clicked()), this, SLOT(buttonStep3()));

    connect(UI.checkBoxColModel, SIGNAL(clicked()), this, SLOT(rebuildVisualization()));
    connect(UI.checkBoxRobot, SIGNAL(clicked()), this, SLOT(rebuildVisualization()));
    connect(UI.checkBoxFloor, SIGNAL(clicked()), this, SLOT(rebuildVisualization()));
    connect(UI.checkBoxObstacles, SIGNAL(clicked()), this, SLOT(rebuildVisualization()));
    connect(UI.checkBoxOption1, SIGNAL(clicked()), this, SLOT(checkBoxOption1()));

    QString scene1("Empty");
    QString scene2("Cylinder");
    QString scene3("Trap");
    UI.comboBoxScene->addItem(scene1);
    UI.comboBoxScene->addItem(scene2);
    UI.comboBoxScene->addItem(scene3);

    QString algo1("PF Planner");
    QString algo2("RRT Planner");
    QString algo3("A* Planner");
    UI.comboBoxAlgo->addItem(algo1);
    UI.comboBoxAlgo->addItem(algo2);
    UI.comboBoxAlgo->addItem(algo3);

    connect(UI.comboBoxScene, SIGNAL(activated(int)), this, SLOT(comboBoxSelectScene(int)));
    connect(UI.comboBoxAlgo, SIGNAL(activated(int)), this, SLOT(comboBoxSelectAlgorithm(int)));

    connect(UI.horizontalSliderTrajectory, SIGNAL(valueChanged(int)), this, SLOT(sliderTrajectory(int)));
}


void PathPlanningWindow::resetSceneryAll()
{
    if (!robot)
    {
        return;
    }

    comboBoxSelectScene(UI.comboBoxScene->currentIndex());
}



void PathPlanningWindow::checkBoxOption1()
{
    std::cout << "option 1 clicked" << std::endl;
}

void PathPlanningWindow::rebuildVisualization()
{
    SceneObject::VisualizationType colModel = (UI.checkBoxColModel->isChecked())?SceneObject::Collision:SceneObject::Full;

    robotSep->removeAllChildren();

    if (robot && UI.checkBoxRobot->isChecked())
    {
        CoinVisualizationPtr visualization = robot->getVisualization<CoinVisualization>(colModel);
        SoNode* visualisationNode = nullptr;
        if (visualization)
        {
            visualisationNode = visualization->getCoinVisualization();
        }

        if (visualisationNode)
        {
            robotSep->addChild(visualisationNode);
        }
    }

    obstacleSep->removeAllChildren();
    if (obstacles && UI.checkBoxObstacles->isChecked())
    {

        for (size_t i = 0; i < obstacles->getSceneObjects().size(); i++)
        {
            CoinVisualizationPtr visualization = obstacles->getSceneObjects().at(i)->getVisualization<CoinVisualization>(colModel);
            SoNode* visualisationNode = nullptr;
            if (visualization)
            {
                visualisationNode = visualization->getCoinVisualization();
            }

            if (visualisationNode)
            {
                obstacleSep->addChild(visualisationNode);
            }
        }
    }

    floorSep->removeAllChildren();
    if (floor && UI.checkBoxFloor->isChecked())
    {
        CoinVisualizationPtr visualization = floor->getVisualization<CoinVisualization>(colModel);
        SoNode* visualisationNode = nullptr;
        if (visualization)
        {
            visualisationNode = visualization->getCoinVisualization();
        }

        if (visualisationNode)
        {
            floorSep->addChild(visualisationNode);
        }
    }
}


void PathPlanningWindow::closeEvent(QCloseEvent* event)
{
    quit();
    QMainWindow::closeEvent(event);
}



int PathPlanningWindow::main()
{
    SoQt::show(this);
    SoQt::mainLoop();
    return 0;
}


void PathPlanningWindow::quit()
{
    std::cout << "PathPlanningWindow: Closing" << std::endl;
    this->close();
    SoQt::exitMainLoop();
}

void PathPlanningWindow::buttonRunPlanner()
{
    if (!robot)
    {
        return;
    }

    Eigen::Matrix4f gp = robot->getGlobalPose();
    Eigen::Vector2f pos = simox::math::position(gp).head<2>();
    std::vector<Eigen::Vector2f> result = planner->plan(pos, params.goal);

    trajectory = result;
    showTrajectory(trajectory);
}

void PathPlanningWindow::visualizeGrid()
{
    std::cout << "Build grid ..." << std::endl;

    float xdist = 100, ydist = 100;
    std::vector<Planner2D::Point2D> grid = planner->getGridVisu(xdist, ydist, params.goal);

    std::cout << "Visualize grid (" << grid.size() << " points) ..." << std::endl;
    gridSep->removeAllChildren();

    SoSeparator* s = new SoSeparator;
    gridSep->addChild(s);

    SoUnits* u = new SoUnits;
    u->units = SoUnits::MILLIMETERS;
    s->addChild(u);

    SoSphere* sphere = new SoSphere;
    sphere->radius = 10.0f;

    Eigen::Matrix4f pos = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f to = Eigen::Matrix4f::Identity();
    for (size_t i = 0; i < grid.size(); i++)
    {
        const Planner2D::Point2D& point = grid[i];

        SoSeparator* s2 = new SoSeparator;
        pos.block<2, 1>(0, 3) = point.pos;
        to.block<2, 1>(0, 3) = point.pos + 50 * point.dir.normalized();

        s2->addChild(CoinVisualizationFactory::getMatrixTransform(pos));
        s2->addChild(sphere);
        s->addChild(s2);

        float angle = std::atan2(point.dir.y(), point.dir.x());
        Eigen::Vector3f hsv{simox::math::rad_to_deg(angle), 1.0, 1.0};
        Eigen::Vector3f rgb = simox::color::hsv_to_rgb(hsv);

        s->addChild(CoinVisualizationFactory::createCoinLine(pos, to, 5.f, rgb(0), rgb(1), rgb(2)));
    }
}

void PathPlanningWindow::buttonStep2()
{
    std::cout << "Step 2..." << std::endl;
}

void PathPlanningWindow::buttonStep3()
{
    std::cout << "Step 3..." << std::endl;
}

void PathPlanningWindow::showTrajectory(std::vector< Eigen::Vector2f > &traj)
{
    trajectorySep->removeAllChildren();

    SoSeparator* s = new SoSeparator;
    trajectorySep->addChild(s);

    SoUnits* u = new SoUnits;
    u->units = SoUnits::MILLIMETERS;
    s->addChild(u);

    SoSphere* sphere = new SoSphere;
    sphere->radius = 10.0f;

    Eigen::Matrix4f m = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f mold = Eigen::Matrix4f::Identity();
    for (size_t i = 0; i < traj.size(); i++)
    {
        SoSeparator* s2 = new SoSeparator;
        m.block(0, 3, 2, 1) = traj[i];
        s2->addChild(CoinVisualizationFactory::getMatrixTransform(m));
        s2->addChild(sphere);
        s->addChild(s2);
        if (i > 0)
        {
            s->addChild(CoinVisualizationFactory::createCoinLine(mold, m, 1.5f, 0, 0, 1.f));
        }
        mold = m;
    }
}

void PathPlanningWindow::sliderTrajectory(int pos)
{
    float fPos = float(pos) / 10.0f;

    // update trajectory
    if (robot && trajectory.size() > 0)
    {
        int trajNr = int(trajectory.size() * fPos/100.0f);
        Eigen::Matrix4f m = Eigen::Matrix4f::Identity();
        if (trajNr >= int(trajectory.size()))
        {
            trajNr = trajectory.size() - 1;
        }
        m.block(0, 3, 2, 1) = trajectory[trajNr];
        robot->setGlobalPose(m);
    }

    UI.lcdNumberTrajectory->display((double)fPos);
}


void PathPlanningWindow::comboBoxSelectScene(int scene)
{
    std::cout << "Loading Scene nr " << (scene+1) << ". File:" << sceneFiles[scene] << std::endl;
    loadScene(sceneFiles[scene]);
    // (re-) setup planner
    comboBoxSelectAlgorithm(UI.comboBoxAlgo->currentIndex());
}

void PathPlanningWindow::comboBoxSelectAlgorithm(int algo)
{
    if (!robot)
    {
        return;
    }

    std::cout << "Selecting algorithm: " << algo << std::endl;
    if (algo == 0)
    {
        planner.reset(new PFPlanner(robot, obstacles, params.common.goalReachedEpsilon, 
                                    params.pf.cAtt, params.pf.cRep, params.pf.cAreaOfInfluence));
    }
    else if (algo == 1)
    {
        planner.reset(new RRTPlanner(robot, obstacles, params.common.goalReachedEpsilon,
                                     params.rrt.incrementalDistance, params.rrt.randomNodeGoal));
    }
    else if (algo == 2)
    {
        float cellSize = 100;
        planner.reset(new AStarPlanner(robot, obstacles, params.astar.cellSize));
    }
    planner->setRobotColModel("Platform");
}

void PathPlanningWindow::loadScene(std::string sceneFile)
{
    robotSep->removeAllChildren();
    std::cout << "Loading Scene from " << sceneFile << std::endl;
    scene.reset();
    robot.reset();

    try
    {
        scene = SceneIO::loadScene(sceneFile);
    }
    catch (VirtualRobotException &e)
    {
        std::cout << " ERROR while creating scene" << std::endl;
        std::cout << e.what();
        return;
    }

    if (!scene)
    {
        std::cout << " ERROR while creating scene" << std::endl;
        return;
    }
    loadRobot(robotFilename);
    scene->registerRobot(robot);

    obstacles = scene->getSceneObjectSet("Obstacles");
    if (!obstacles)
    {
        std::cout << "No SceneObjectSet with name 'Obstacles' found in scene definition!!!" << std::endl;
    }
    floor = scene->getObstacle("Floor");

    // build visualization
    rebuildVisualization();
    viewer->viewAll();

    // reset trajectory
    trajectory.clear();
    showTrajectory(trajectory);
}

