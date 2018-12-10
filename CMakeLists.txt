cmake_minimum_required(VERSION 3.12)
project(OOP_Lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_Lab_6 main.cpp Bignum.cpp Bignum.h Fraction.cpp Fraction.h Matrix.cpp Matrix.h Exception.cpp Exception.h MathException.cpp MathException.h InputException.cpp InputException.h MemoryException.cpp MemoryException.h DivideByZeroException.cpp DivideByZeroException.h)