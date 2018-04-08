cmake_minimum_required(VERSION 3.8)

project(TpGame)

target_compile_features(${TARGET} PUBLIC cxx_std_11)

add_definitions(-Wall -O2)

if(DEBUG)

	set(CMAKE_BUILD_TYPE Debug)

else()

	set(CMAKE_BUILD_TYPE Release)

endif()

add_executable(main main.cpp army.h player.h test.h)

if(WITH_TEST)

    add_definitions(-DWITH_TEST)

    target_link_libraries(main gtest)

    target_link_libraries(main pthread)

endif()