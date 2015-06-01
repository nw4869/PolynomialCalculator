cmake_minimum_required(VERSION 3.2)
project(task2_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(task2_1 ${SOURCE_FILES} Polynomial.cpp Polynomial.h Operation.h Operators.h  ReversePolishCalculator.h PolynomialCalculator.cpp PolynomialCalculator.h)