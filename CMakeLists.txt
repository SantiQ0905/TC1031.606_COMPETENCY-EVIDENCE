cmake_minimum_required(VERSION 3.16)
project(TC1031_CompetencyEvidence)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(TC1031_CompetencyEvidence src/main.cpp
        src/main.cpp
        src/FileHandler.cpp
        src/Record.cpp
        src/Date.cpp
        src/IPAddress.cpp
        src/BinarySearchTree.tpp
        include/Date.h
        include/FileHandler.h
        include/IPAddress.h
        include/Record.h
        include/BinarySearchTree.h
        include/GraphUtils.h
        src/GraphUtils.cpp)
