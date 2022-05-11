cmake_minimum_required(VERSION 3.0.0)

project(Ravesli)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(chapters)
add_subdirectory(lessons)
add_subdirectory(temp)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  Chapters
  Lessons
)