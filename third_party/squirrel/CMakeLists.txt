

cmake_minimum_required(VERSION 2.8)

project(squirrel)

if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

set (MODULES sq sqstdlib squirrel)

foreach(MOD ${MODULES})
	add_subdirectory(${MOD})
endforeach()
