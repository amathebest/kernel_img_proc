cmake_minimum_required(VERSION 3.15)
project(kernel_img_proc)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR "I:\\Matteo\\Downloads\\opencv-4.2.0\\build\\install")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(kernel_img_proc main.cpp utils.h utils.cpp Image.h)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(kernel_img_proc ${OpenCV_LIBS})
