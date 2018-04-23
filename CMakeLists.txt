cmake_minimum_required(VERSION 3.5)

project(TpGame)

OPTION(WITH_TEST OFF)

OPTION(DEBUG OFF)

set(CMAKE_CXX_STANDARD 11)


if(DEBUG)

	set(CMAKE_BUILD_TYPE Debug)

else(DEBUG)

	set(CMAKE_BUILD_TYPE Release)

endif(DEBUG)


if (WITH_TEST)

    add_subdirectory(googletest-master)

    include_directories(googletest-master/googletest/include)

    set(SOURCE_FILES Player.h Army.h Union.h Buf.h test.h test.cpp main.cpp)

    add_executable(TpGame ${SOURCE_FILES})

    target_link_libraries(TpGame gtest)

    target_link_libraries(TpGame pthread)

else (WITH_TEST)

    set(SOURCE_FILES Player.h Army.h Union.h Buf.h main.cpp)

    add_executable(TpGame ${SOURCE_FILES})

endif(WITH_TEST)
