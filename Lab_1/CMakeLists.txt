cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME Lab_1)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

include_directories("inc")
add_executable("${PROJECT_NAME}" main.cpp inc/func.hpp src/func.cpp)
#add_definitions(-DRESOURCES_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/file/\")
configure_file(file/run.txt ${CMAKE_CURRENT_BINARY_DIR}/file/run.txt COPYONLY)
#add_custom_command(
 #   TARGET Lab_1 POST_BUILD
  #  COMMAND ${CMAKE_COMMAND} -E copy
	# 			${CMAKE_CURRENT_BINARY_DIR}/file/run.txt
    #        ${CMAKE_SOURCE_DIR}/file/run.txt)


