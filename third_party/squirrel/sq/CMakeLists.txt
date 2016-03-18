
set(TARGET_NAME sq)

add_executable(${TARGET_NAME} sq.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
target_link_libraries(${TARGET_NAME} squirrel sqstdlib)
include_directories(${PROJECT_SOURCE_DIR}/include)
