cmake_minimum_required(VERSION 3.27)
project(3_IN_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(3_IN_1 main.cpp NumberScrabble.cpp
        "The 100 Game.cpp"
        "Subtract a square.cpp")
