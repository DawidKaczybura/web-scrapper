cmake_minimum_required(VERSION 3.18.4)

set(This tests)

set(Sources
    #../Buffer.cpp
    RetrieverTest.cpp
)

add_executable(${This} ${Sources})

get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR})

target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

execute_process(COMMAND test/tests)

