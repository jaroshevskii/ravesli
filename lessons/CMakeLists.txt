project(Lessons)

add_subdirectory(lesson113)
add_subdirectory(lesson114)
add_subdirectory(lesson116)
add_subdirectory(lesson117)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  Lesson113
  Lesson114
  Lesson116
  Lesson117
)