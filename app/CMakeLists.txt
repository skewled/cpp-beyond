cmake_minimum_required(VERSION 3.18.4)

set(This app)

set(Headers
    include/app/Circle.h
    include/app/Landscape.h
    include/app/NotImplException.h
    include/app/Rectangle.h
    include/app/RgbColor.h
)

set(Sources
    src/Circle.cpp
    src/Landscape.cpp
    src/Rectangle.cpp
    src/RgbColor.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC include)