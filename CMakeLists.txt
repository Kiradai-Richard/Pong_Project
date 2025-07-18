cmake_minimum_required(VERSION 3.10)
project(Pong_Project)
include_directories(${PROJECT_SOURCE_DIR}/HeaderFiles/)
add_executable(Pong ${PROJECT_SOURCE_DIR}/SourceFiles/main.cpp
                    ${PROJECT_SOURCE_DIR}/SourceFiles/BallClass.cpp
                    ${PROJECT_SOURCE_DIR}/SourceFiles/PongClass.cpp
                   
)