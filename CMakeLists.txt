cmake_minimum_required(VERSION 3.5)
project(imseg_generator)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FIND_PACKAGE( OpenCV REQUIRED core highgui imgproc)
include_directories(${OpenCV_INCLUDE_DIRS})
# add libs you need
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui)

set(SOURCE_FILES main.cpp)
add_executable(imseg_generator ${SOURCE_FILES})

# linking
target_link_libraries(imseg_generator ${OpenCV_LIBS})
