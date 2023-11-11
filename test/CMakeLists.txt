cmake_minimum_required(VERSION 3.8)

set(This Password_generator_tests)

add_executable(${This}
    password_generator_tests.cpp
)

target_link_libraries(${This} PUBLIC
    gtest_main
    Password_generator
)

add_test(
    NAME ${This}
    COMMAND ${This}
)