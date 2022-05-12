#include <Inventor/Qt/SoQt.h>

#include "PathPlanningWindow.h"


int main(int argc, char *argv[])
{
    SoDB::init();
    SoQt::init(argc, argv, "PathPlanning");

    //std::string sceneFile("robots/ArmarIII/ArmarIII.xml");

    /*
    std::string robotName ("ArmarIII");
    std::string config1 ("start");
    std::string config2 ("end");

    std::cout << "Using scene file " << sceneFile << std::endl;
    */

    PathPlanningWindow* rw = new PathPlanningWindow();

    rw->main();
    delete rw;
    SoDB::cleanup();

    return 0;
}
