cmake_minimum_required(VERSION 3.23)
project(FTLibrary)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(FTLibrary main.cpp FList.h FVector.h test.cpp)
target_link_libraries(FTLibrary gtest_main)
add_test(NAME test COMMAND FTLibrary)


#target_link_libraries(FTLibrary)
