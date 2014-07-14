# vim: shiftwidth=2 softtabstop=2 tabstop=2 expandtab
#
# This file is part of the HotFish project
# Copyright (c) 2014, Lucky Green Frog, LLC
#

cmake_minimum_required(VERSION 2.8)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(
    FATAL_ERROR
      "You are in the top-level source folder. Please build in a subfolder."
  )
endif()

# must appear before 'project' command
if (NOT CMAKE_INSTALL_PREFIX)
  set(
    CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/local" CACHE PATH
    "Install path prefix, prepended onto install directories."
    FORCE
    )
endif()

project(yare)

if (NOT CMAKE_BUILD_TYPE)
  set(
    CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build: Debug, Release, RelWithDebInfo, or MinSizeRel."
    FORCE
  )
endif()

add_subdirectory(src)
add_subdirectory(tests EXCLUDE_FROM_ALL)
