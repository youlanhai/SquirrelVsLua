
set(TARGET_NAME sqstdlib)

file(GLOB SOURCE_FILES *.h *.cpp)

add_library(${TARGET_NAME} ${SOURCE_FILES})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include)
