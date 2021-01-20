cmake_minimum_required(VERSION 3.1)
project(vtk2osg)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-Wall)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenSceneGraph REQUIRED osg osgViewer osgDB osgGA osgUtil)
find_package(VTK REQUIRED)

include(${VTK_USE_FILE})
include_directories(include ${OPENSCENEGRAPH_INCLUDE_DIRS} ${VTK_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp vtk2osg.cpp)
target_link_libraries(${PROJECT_NAME} ${OPENSCENEGRAPH_LIBRARIES} ${VTK_LIBRARIES})
