cmake_minimum_required(VERSION 3.5)
project(cmrosutils)

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


## CarMaker specific

# To prevent loading a variable from the CMake Cache, add the FORCE option:
# https://cmake.org/cmake/help/latest/command/set.html#set-cache-entry
set(CARMAKER_VER 11.0 CACHE STRING "Desired CarMaker version, e.g. 11.0.1")

set(IPGHOME "/tools/carmaker" CACHE PATH "Path to CarMaker installation")

set(CARMAKER_IPGHOME_DIRS "/tools/carmaker"
    CACHE STRING "List of possible CarMaker installation root dirs, e.g. '/opt/ipg'")


find_path(CARMAKER_DIR
    DOC "CarMaker ${CARMAKER_VER} installation directory."
    NAMES "include/CarMaker.h"
    HINTS ${CARMAKER_IPGHOME_DIRS}
    PATH_SUFFIXES carmaker/linux64-${CARMAKER_VER}
)

set(CARMAKER_VER "14.0.1")
set(CARMAKER_DIR /tools/carmaker/CM14/carmaker/linux64-${CARMAKER_VER})


if(NOT EXISTS ${CARMAKER_DIR}/include)
    message(FATAL_ERROR
        "Can't find CarMaker installation for $CARMAKER_VER: '${CARMAKER_VER}'\
         in any of the following places: $CARMAKER_IPGHOME_DIRS='${CARMAKER_IPGHOME_DIRS}'.\n"
        "Possible solutions:\n"
        " - Change the desired CarMaker version in $CARMAKER_VER\n"
        " - Use the environment variable $IPGHOME\n"
        " - Or extend the list of installation root dirs in $CARMAKER_IPGHOME_DIRS")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE_ON)
add_definitions(-DCARMAKER_VER=${CARMAKER_VER})
add_definitions(-DROS_DISTRO=$ENV{ROS_DISTRO})


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/CMRemoteControl.srv"
  DEPENDENCIES
    builtin_interfaces
 )

## Declare a C++ library

find_library(CMJob_LIB NAMES "CMJob" PATHS "lib")

add_library(cmrosif SHARED
  src/cmrosif.cpp
)

ament_target_dependencies(cmrosif
  rclcpp
 )

if(NOT DEFINED ENV{ROS_DISTRO})
  message(FATAL_ERROR "ROS_DISTRO environment variable is undefined, please make sure a valid ROS installation is sourced.")
endif()

string(TOUPPER "$ENV{ROS_DISTRO}" ROS_DISTRO_UPPER)

if(ROS_DISTRO_UPPER STRLESS "HUMBLE")
  rosidl_target_interfaces(cmrosif
    ${PROJECT_NAME} "rosidl_typesupport_cpp")

  target_link_libraries(cmrosif
    ${CMJob_LIB}
  )
else()
  rosidl_get_typesupport_target(cpp_typesupport_target
    ${PROJECT_NAME} rosidl_typesupport_cpp
  )

  target_link_libraries(cmrosif
    ${CMJob_LIB}
    "${cpp_typesupport_target}"
  )
endif()


target_include_directories(cmrosif
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CARMAKER_DIR}/include>
    $<INSTALL_INTERFACE:include>
    $<INSTALL_INTERFACE:${CARMAKER_DIR}/include>
 )

if(COMMAND ament_export_targets)
  ament_export_targets(cmrosifTargets HAS_LIBRARY_TARGET)
else()
  ament_export_libraries(cmrosif)
  ament_export_include_directories(include ${CARMAKER_DIR}/include)
  ament_export_dependencies(rclcpp)
  ament_export_dependencies(rosidl_default_runtime)
endif()

install(
  DIRECTORY include/
  DESTINATION include
 )

install(
  TARGETS cmrosif
  EXPORT cmrosifTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
 )

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
