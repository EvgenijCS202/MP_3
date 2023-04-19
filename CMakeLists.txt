cmake_minimum_required(VERSION 3.5)

project(MP_Lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CHILD child.h child.cpp)
set(FILES files.hpp)
set(SORTS sorts.h sorts.cpp)
set(SEARCH search.h search.cpp)
set(CONSTANTS constants.h)
set(HASH hash.hpp)

add_executable(MP_Lab3 main.cpp ${CHILD} ${FILES} ${SORTS} ${SEARCH} ${HASH})
