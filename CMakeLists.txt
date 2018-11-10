cmake_minimum_required(VERSION 3.12)
project(gofish)

set(CMAKE_CXX_STANDARD 14)

add_executable(gofish card.cpp card.h deck.cpp deck.h player.cpp player.h go_fish.cpp go_fish.h)