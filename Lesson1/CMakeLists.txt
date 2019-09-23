project(Lesson1)
add_executable(Lesson1 src/main.cpp)
target_link_libraries(Lesson1 utils SDL2::SDL2)
install(TARGETS Lesson1 RUNTIME DESTINATION ${BIN_DIR})

