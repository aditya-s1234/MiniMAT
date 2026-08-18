cmake_minimum_required(VERSION 4.2)
project(MiniMAT)

set(CMAKE_CXX_STANDARD 20)

add_executable(MiniMAT main.cpp
        Matrix.cpp
        Matrix.h
        Application.cpp
        Application.h
        Vector.cpp
        Vector.h
        Lexer.cpp
        Lexer.h
        Parser.cpp
        Parser.h
)
