cmake_minimum_required (VERSION 3.8)

add_library(sat_code
    sat_code/sgp.cpp sat_code/sgp4.cpp sat_code/sgp8.cpp sat_code/sdp4.cpp sat_code/sdp8.cpp sat_code/deep.cpp sat_code/basics.cpp sat_code/get_el.cpp sat_code/common.cpp sat_code/tle_out.cpp sat_code/observe.cpp
    )

target_include_directories(sat_code PUBLIC sat_code/norad.h sat_code/observe.h)