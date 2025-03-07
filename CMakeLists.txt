cmake_minimum_required(VERSION 3.31.0)

project(App LANGUAGES CXX C)

include_directories(include)

aux_source_directory(src SRC)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libglfw3.a)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libfreetype.a)