cmake_minimum_required(VERSION 3.23)
project(TicTacToeInC C)

set(CMAKE_C_STANDARD 17)

add_executable(TicTacToeInC main.c interface.c interface.h)
