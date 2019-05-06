cmake_minimum_required(VERSION 2.8.3)
project(framer)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  genmsg
  qt_build
  roscpp
  roslib
)

find_package(Qt4 REQUIRED COMPONENTS
  QtCore
  QtGui
)

find_package(OpenCV REQUIRED)

################################################
## Declare ROS messages, services and actions ##
################################################


################################################
## Find files
################################################
file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
set(QT_MOC include/framer/framer.h)
SET(QT_SOURCES src/framer.cpp)

################################################
## Setup QT
################################################
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

###################################
## catkin specific configuration ##
###################################
catkin_package(
  CATKIN_DEPENDS message_runtime
)

###########
## Build ##
###########



include(
  ${QT_USE_FILE}
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${QT_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
)
add_library(qt_lib ${QT_SOURCES} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(qt_lib ${QT_LIBRARIES} ${catkin_LIBRARIES} ${OPENCV_LIBS})

add_library(framer_lib include/framer/framer.h  src/framer.cpp)
target_link_libraries(framer_lib qt_lib)

add_executable(framer src/main.cpp)
target_link_libraries(framer framer_lib)
