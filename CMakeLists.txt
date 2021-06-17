cmake_minimum_required (VERSION 3.0)
project (bridge)

# Put binary in a bin dir.
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set (SOURCES
	src/example.c
	src/lidarlite_v3.cpp
	src/lidarlite_v3_wrapper.cpp
	src/lidarlite_v3.h
	src/lidarlite_v3_wrapper.h
)

add_executable (${PROJECT_NAME} ${SOURCES})
 
