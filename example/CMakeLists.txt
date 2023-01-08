cmake_minimum_required(VERSION 3.18.4)

set(This appexample)

set(Sources
    src/app.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Examples
)

target_link_libraries(${This} PUBLIC
    app
)

add_test(
    NAME ${This}
    COMMAND ${This}
)