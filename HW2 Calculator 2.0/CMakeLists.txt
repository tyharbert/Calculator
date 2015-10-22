cmake_minimum_required(VERSION 3.3)

# project declarations
project(calc_lib CXX)
project(calc CXX)

# compiler library
file(GLOB calc_lib_src
    "Library/*.cpp"
)

add_library(calc_lib STATIC
    ${calc_lib_src}
)

# calculator program
add_executable(calc Exe/main.cpp)

target_link_libraries(calc LINK_PUBLIC calc_lib)
