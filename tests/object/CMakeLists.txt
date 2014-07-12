
cmake_minimum_required(VERSION 2.8)

set(
  TEST_SOURCES
    main.c
)

include_directories("${CMAKE_INSTALL_PREFIX}/include")
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

add_executable(
  hftest
  ${TEST_SOURCES}
)

target_link_libraries(
  hftest
    hfcore
)

