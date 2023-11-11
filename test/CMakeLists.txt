cmake_minimum_required(VERSION 3.8)

set(This PasswordGeneratorTest)

add_executable(${This}
    password_generator_tests.cpp
)

target_link_libraries(${This} PUBLIC
    gtest_main
    Password_generator
)

enable_testing()
add_test(
    NAME ${This}
    COMMAND ${This}
)