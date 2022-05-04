cmake_minimum_required(VERSION 2.8.3)
project(qt_ros)


add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
 roscpp
 std_msgs
)

######################
## QT configuration ##
######################

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package()

###########
## Build ##
###########

include_directories(
# include
 ${catkin_INCLUDE_DIRS}
)

###########
## Build ##
###########

add_executable(qt_ros_node ros/main.cpp ros/qttest.cpp ros/qttest.ui ros/rosthread.cpp)
target_link_libraries(qt_ros_node ${catkin_LIBRARIES} Qt5::Core Qt5::Gui Qt5::Widgets)

