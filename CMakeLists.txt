cmake_minimum_required(VERSION 3.29)
project(epfu25w_101_f_penguins C)

set(CMAKE_C_STANDARD 11)

include_directories(T5)

add_executable(epfu25w_101_f_penguins
    T5/fileio.c
    T5/fileio.h
    T5/game.c
    T5/game.h
    T5/gameconfig.c
    T5/gameconfig.h
    T5/main.c
        T5/placementalgorithm.c
        T5/placementalgorithm.h
        T5/movementalgorithm.c
        T5/movementalgorithm.h)
