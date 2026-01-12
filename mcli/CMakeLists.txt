set(HEADERS
    mcli.h
)

set(SOURCES
    mcli.c
)

add_library(mcli ${SOURCES})

target_include_directories(mcli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})