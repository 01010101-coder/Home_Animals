cmake_minimum_required(VERSION 3.26)
project(Home_Animals)

set(CMAKE_CXX_STANDARD 17)

add_executable(Home_Animals main.cpp
        Animals/Animal.h
        Animals/Animal.cpp
        Animals/Cat.h
        User.h
        User.cpp
        Animals/Dog.h
        Animals/Fish.h
        Animals/Hamster.h
        Animals/Factory.h
        Animals/Composite.h
        Animals/Factory_two.h
)
