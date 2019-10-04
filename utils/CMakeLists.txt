project(utils)
set(SOURCES src/utils.cpp)
add_library(utils STATIC ${SOURCES})
target_link_libraries(utils SDL2::SDL2)

