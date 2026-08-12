cmake_minimum_required(VERSION 3.20)

project(
    maplab
    VERSION 0.1.0
    LANGUAGES CXX
)

add_library(maplab INTERFACE)

target_include_directories(maplab
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(maplab INTERFACE cxx_std_20)

option(ML_BUILD_APPS "Build apps" ON)
if(ML_BUILD_APPS)
    add_subdirectory(apps)
endif()

# ------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------

option(ML_BUILD_TESTS "Build tests" OFF)
if(ML_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# ------------------------------------------------------------------
# Benchmarks
# ------------------------------------------------------------------

option(ML_BUILD_BENCH "Build bench" OFF)
if(ML_BUILD_BENCH)
    add_subdirectory(bench)
endif()
