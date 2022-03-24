cmake_minimum_required(VERSION 3.5)

project(Ravesli)

add_subdirectory(lessons)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  Lesson113
  Lesson114
)