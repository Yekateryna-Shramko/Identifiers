cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.0
)

FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(tests test_main.cpp runway.cpp runway.h)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_test(NAME AllTests COMMAND tests)

add_executable(runwaybin main.cpp runway.cpp runway.h)
