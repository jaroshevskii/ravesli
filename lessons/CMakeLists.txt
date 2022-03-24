cmake_minimum_required(VERSION 3.5)

project(Lessons)

add_subdirectory(lesson113)
add_subdirectory(lesson114)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  Lesson113
  Lesson114
)