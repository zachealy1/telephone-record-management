cmake_minimum_required(VERSION 3.31)
project(telephone_record_management C)

set(CMAKE_C_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
        src/main.c
        src/file_io.c
        src/analysis.c
)

# Build the executable from those sources
add_executable(telephone_record_management ${SOURCES})
