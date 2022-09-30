cmake_minimum_required(VERSION 3.23)
project(FTLibrary)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

add_executable(FTLibrary main.cpp FList.h FVector.h test.cpp)
target_link_libraries(FTLibrary gtest_main)
add_test(NAME test COMMAND FTLibrary)


#target_link_libraries(FTLibrary)
