cmake_minimum_required(VERSION 3.18.4)

set(This menu)

set(Headers
    include/menu/Menu.h
)

set(Sources
    src/Menu.cpp
    src/MenuApp.cpp
)

add_executable(${This} ${Sources})
set_target_properties(${This} PROPERTIES
    FOLDER Examples
)

target_include_directories(${This} PUBLIC include)