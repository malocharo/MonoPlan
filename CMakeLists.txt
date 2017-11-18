cmake_minimum_required(VERSION 3.8)
project(MonoPlan)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c pile.c pile.h liste.c liste.h test_unit.c test_unit.h)
add_executable(MonoPlan ${SOURCE_FILES} pile.c pile.h liste.c liste.h test_unit.c test_unit.h)