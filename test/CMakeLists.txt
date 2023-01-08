cmake_minimum_required(VERSION 3.18.4)

set(This appTests)

set(Sources
    src/CircleTests.cpp
    src/RectangleTests.cpp
    src/RgbColorTest.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Tests
)

target_link_libraries(${This} PUBLIC
    gtest_main
    app
)

add_test(
    NAME ${This}
    COMMAND ${This}
)