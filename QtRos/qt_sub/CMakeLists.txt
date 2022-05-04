cmake_minimum_required(VERSION 3.0.2)
project(qt_sub)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(qt_sub_node ros/main.cpp)
target_link_libraries(qt_sub_node ${catkin_LIBRARIES} )