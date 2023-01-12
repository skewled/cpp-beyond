cmake_minimum_required(VERSION 3.18.4)

set(This app)

set(Headers
    include/app/Circle.h
    include/app/Landscape.h
    include/app/NotImplException.h
    include/app/Rectangle.h
    include/app/RgbColor.h
    include/app/Templates.h
    include/app/Shape.h
    include/app/Measurable.h
)

set(Sources
    src/Circle.cpp
    src/Landscape.cpp
    src/Rectangle.cpp
    src/RgbColor.cpp
    src/Pointers.cpp
    src/Shape.cpp
    src/Measurable.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

target_include_directories(${This} PUBLIC include)