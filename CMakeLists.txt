cmake_minimum_required(VERSION 3.14)
project(OffGridSpatialFramework VERSION 1.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
add_library(OffGridSpatial src/Coordinate.cpp src/Waypoint.cpp src/WaypointManager.cpp)
add_executable(OffGridApp main.cpp)
target_link_libraries(OffGridApp OffGridSpatial)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) 
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(OffGridTests tests/test_engine.cpp)
target_link_libraries(OffGridTests OffGridSpatial GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(OffGridTests)