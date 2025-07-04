cmake_minimum_required(VERSION 3.5)
project(cm_ros_if)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cmrosutils REQUIRED)
find_package(cm_msgs REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/cm_ros_if.cpp
 )

ament_target_dependencies(${PROJECT_NAME}
    rclcpp
    cmrosutils
    cm_msgs
 )

install(TARGETS
   ${PROJECT_NAME}
   DESTINATION lib
 )

#install(DIRECTORY include/
#  DESTINATION include
# )

ament_export_libraries(${PROJECT_NAME})

ament_export_dependencies(rclcpp)
ament_export_dependencies(cmrosutils)
ament_export_dependencies(cm_msgs)
ament_export_dependencies(rosidl_default_runtime)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
