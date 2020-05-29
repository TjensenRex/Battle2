cmake_minimum_required(VERSION 3.16)
project(Battle2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Battle2 main.cpp Human.cpp Human.h Swordsman.cpp Swordsman.h Wizard.cpp Wizard.h Weapon.cpp Weapon.h Enemy.cpp Enemy.h)