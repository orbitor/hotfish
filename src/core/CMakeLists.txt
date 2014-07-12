# vim: shiftwidth=2 softtabstop=2 tabstop=2 expandtab
#
# This file is part of the HotFish project
# Copyright (c) 2014, Lucky Green Frog, LLC
#

include_directories(
  "${CMAKE_CURRENT_LIST_DIR}"
)

set(HF_CORE_LIB_SO_VERSION 0)
set(HF_CORE_LIB_VERSION 0.0.1)

set(
  HF_LIB_CORE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/hf-mem.c
    ${CMAKE_CURRENT_LIST_DIR}/HfObject.c
)

add_library(
  hfcore
    SHARED
    ${HF_LIB_CORE_SOURCES}
)

set_target_properties(
  hfcore
    PROPERTIES
      OUTPUT_NAME hfcore
      ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
      VERSION ${HF_CORE_LIB_VERSION}
      SOVERSION ${HF_CORE_LIB_SO_VERSION}
)

INSTALL(
  TARGETS
    hfcore
  DESTINATION
    lib
)

INSTALL(
  DIRECTORY ./
  DESTINATION
    include
  FILES_MATCHING
    PATTERN
      "*.h"
)

