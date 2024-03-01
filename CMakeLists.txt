cmake_minimum_required (VERSION 3.8)

project(spmp VERSION 1.0.0)

include(CheckIncludeFile)
CHECK_INCLUDE_FILE("immintrin.h" intrinsics_found)

if(NOT intrinsics_found)
    message(FATAL_ERROR "Intrinsics header not found")
endif()

add_subdirectory(lib)

add_library(${PROJECT_NAME} src/sgp.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC inc PRIVATE lib/sat_code)
target_link_libraries(${PROJECT_NAME} sat_code)

enable_testing()
add_subdirectory(test)