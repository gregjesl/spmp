cmake_minimum_required (VERSION 3.8)

project(spmp VERSION 1.0.0)

include(CheckIncludeFile)
CHECK_INCLUDE_FILE("immintrin.h" intrinsics_found)

if(NOT intrinsics_found)
    message(FATAL_ERROR "Intrinsics header not found")
endif()

enable_testing()
add_subdirectory(test)