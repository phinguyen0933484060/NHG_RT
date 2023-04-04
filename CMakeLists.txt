cmake_minimum_required(VERSION 3.0)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
project( NHG_RT )
# find_package( )

set(SOURCE
	src/Mutex.cpp
)
set(HEADERS
    include/Mutex.h
)
include_directories( )
add_executable(  )


target_link_libraries( cau_2 ${OpenCV_LIBS} )

