cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Lab_1)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

#message("${CMAKE_SOURCE_DIR}")

add_definitions(-DPATH="${CMAKE_SOURCE_DIR}")

include_directories("inc")

add_executable("${PROJECT_NAME}" main.cpp inc/func.hpp src/func.cpp)

#configure_file(file/run.txt file/run.txt COPYONLY)
#configure_file(file/run.txt Debug/file/run.txt COPYONLY)
#file(COPY "file/run.txt" DESTINATION "file/")


