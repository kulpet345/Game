cmake_minimum_required(VERSION 3.5)

project(TpGame)

OPTION(WITH_TEST OFF)

set(CMAKE_CXX_STANDARD 11)

if (WITH_TEST)

    add_subdirectory(googletest-master)

    include_directories(googletest-master/googletest/include)

    set(SOURCE_FILES Player.h Army.h Union.h Buf.h test.h test.cpp main.cpp)

    add_executable(TpGame ${SOURCE_FILES})

    target_link_libraries(TpGame gtest)

else (WITH_TEST)

    set(SOURCE_FILES Player.h Army.h Union.h Buf.h test.h test.cpp main.cpp)

    add_executable(TpGame ${SOURCE_FILES})

endif(WITH_TEST)
