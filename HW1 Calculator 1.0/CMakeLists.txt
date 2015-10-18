cmake_minimum_required(VERSION 3.3)

# project declarations
project(calcLib CXX)
project(calc CXX)
project(calc2sexpr CXX)
project(calc2post CXX)

# calculator library
add_library(calcLib STATIC
    Library/parser.cpp
    Library/eval.cpp
)

#Evaluation program
add_executable(calc Eval/main.cpp)

target_link_libraries(calc LINK_PUBLIC calcLib)

#SExpr Program
add_executable(calc2sexpr SExpr/main.cpp)

target_link_libraries(calc2sexpr LINK_PUBLIC calcLib)

#PostFix Program
add_executable(calc2post PostFix/main.cpp)

target_link_libraries(calc2post LINK_PUBLIC calcLib)
