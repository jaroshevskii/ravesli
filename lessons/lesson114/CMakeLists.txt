cmake_minimum_required(VERSION 3.5)

project(Lesson114)

add_subdirectory(task2)
add_subdirectory(task3)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  ${PROJECT_NAME}Task2
  ${PROJECT_NAME}Task3
)