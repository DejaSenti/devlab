cmake_minimum_required(VERSION 3.20)

project(arm_controller VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME}_lib
	src/kinematics/operators.cpp
)

target_include_directories(${PROJECT_NAME}_lib
	PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(${PROJECT_NAME}_lib PUBLIC cxx_std_20)

add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE 
		${PROJECT_NAME}_lib
)

include(CTest)

if (BUILD_TESTING)
	add_executable(${PROJECT_NAME}_test
		test/test_main.cpp
	)

	target_link_libraries(${PROJECT_NAME}_test
		PRIVATE
			${PROJECT_NAME}_lib
	)

	add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
endif()