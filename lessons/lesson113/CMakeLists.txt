cmake_minimum_required(VERSION 3.5)

project(Lesson113)

add_subdirectory(task)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  ${PROJECT_NAME}Task
)