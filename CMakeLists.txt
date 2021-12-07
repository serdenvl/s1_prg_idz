cmake_minimum_required(VERSION 3.0.0)
project(idz VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(idz main.c utils.c task1.c task2.c task3.c task4.c task5.c task6.c task7.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
