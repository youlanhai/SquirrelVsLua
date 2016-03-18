
set(TARGET_NAME squirrel)

file(GLOB SOURCE_FILES *.h *.cpp)
list(APPEND SOURCE_FILES ${PROJECT_SOURCE_DIR}/include/squirrel.h)

add_library(${TARGET_NAME} ${SOURCE_FILES})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include)
