PROJECT ( PathPlanning )

CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)
#CMAKE_POLICY(VERSION 2.6)

GET_FILENAME_COMPONENT (CurrentPath ${CMAKE_CURRENT_LIST_FILE} PATH)

# search for simox
FIND_PACKAGE(Simox REQUIRED)

SET(DEMO_BASE_DIR ${PROJECT_SOURCE_DIR})
ADD_DEFINITIONS(-DDEMO_BASE_DIR="${DEMO_BASE_DIR}")
# cmake 3.10 does not understand c++2a, so we tell it we will handle the standard flag
set(CMAKE_CXX_STANDARD_DEFAULT)
add_definitions(-std=c++2a)

IF(Simox_USE_COIN_VISUALIZATION)

        FILE(GLOB demo_SRCS ${PROJECT_SOURCE_DIR}/PathPlanning.cpp
                            ${PROJECT_SOURCE_DIR}/PathPlanningWindow.cpp
                            ${PROJECT_SOURCE_DIR}/Planner/Node.cpp
                            ${PROJECT_SOURCE_DIR}/Planner/Planner2D.cpp
                            ${PROJECT_SOURCE_DIR}/Planner/PFPlanner.cpp
                            ${PROJECT_SOURCE_DIR}/Planner/RRTPlanner.cpp
                            ${PROJECT_SOURCE_DIR}/Planner/AStarPlanner.cpp
	                    )

        FILE(GLOB demo_INCS ${PROJECT_SOURCE_DIR}/PathPlanningWindow.h
                            ${PROJECT_SOURCE_DIR}/Planner/Node.h
                            ${PROJECT_SOURCE_DIR}/Planner/Planner2D.h
                            ${PROJECT_SOURCE_DIR}/Planner/PFPlanner.h
                            ${PROJECT_SOURCE_DIR}/Planner/RRTPlanner.h
                            ${PROJECT_SOURCE_DIR}/Planner/AStarPlanner.h
	                    )



    ################################## moc'ing ##############################
    set(mocFiles
        ${PROJECT_SOURCE_DIR}/PathPlanningWindow.h
    )

    set(uiFiles
        ${PROJECT_SOURCE_DIR}/PathPlanning.ui
    )

    add_definitions( -DDEMO_PATH=\"${PROJECT_SOURCE_DIR}\" )
    message(STATUS "flags: ${CMAKE_CXX_FLAGS}")
    # create the executable
    VirtualRobotQtApplication(${PROJECT_NAME} "${demo_SRCS}" "${demo_INCS}" "${GUI_MOC_HDRS}" "${GUI_UIS}")

ENDIF()
