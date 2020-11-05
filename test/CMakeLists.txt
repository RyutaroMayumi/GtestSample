cmake_minimum_required(VERSION 2.8)
project(gtest-sample)


# setup google test
include(cmake/DownloadProject/DownloadProject.cmake)
download_project(
    PROJ googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    UPDATE_DISCONNECTED 1
)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})


# set test target
include_directories(../include)
add_library(Accumulator ../source/Accumulator.cpp)
add_library(Multiplier ../source/Multiplier.cpp)
add_executable(accumulator-test ./src/Accumulator_test.cpp)
target_link_libraries(accumulator-test
    Accumulator
    gtest_main
)
add_executable(multiplier-test ./src/Multiplier_test.cpp)
target_link_libraries(multiplier-test
    Multiplier  # 順番を変えるとリンクエラーになる
    Accumulator
    gtest_main
)


# run test
enable_testing()    # make testのために必要
include(GoogleTest) # gtest_discover_tests()のために必要
gtest_discover_tests(accumulator-test)
gtest_discover_tests(multiplier-test)
