# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cm_ros_if_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cm_ros_if_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cm_ros_if_FOUND FALSE)
  elseif(NOT cm_ros_if_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cm_ros_if_FOUND FALSE)
  endif()
  return()
endif()
set(_cm_ros_if_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cm_ros_if_FIND_QUIETLY)
  message(STATUS "Found cm_ros_if: 1.0.0 (${cm_ros_if_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cm_ros_if' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cm_ros_if_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cm_ros_if_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${cm_ros_if_DIR}/${_extra}")
endforeach()
