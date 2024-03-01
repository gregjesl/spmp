cmake_minimum_required (VERSION 3.8)

file(GLOB tests
    "*.cpp"
)

foreach(test ${tests})
    string(REGEX REPLACE ".*/" "" test_name "${test}")
    string(REGEX REPLACE ".cpp$" "" test_name "${test_name}")
    add_executable (test_name ${test})
    target_link_libraries(test_name ${PROJECT_NAME} sat_code)
    target_include_directories(test_name PRIVATE ../lib/sat_code)
	if(MSVC)
		set_property(TARGET test_name PROPERTY _CRT_SECURE_NO_WARNINGS)
	endif()
    add_test(NAME ${test_name} COMMAND test_name)
endforeach()