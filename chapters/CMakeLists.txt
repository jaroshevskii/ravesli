project(Chapters)

# add_subdirectory(chapter1)
# add_subdirectory(chapter2)
# add_subdirectory(chapter3)
# add_subdirectory(chapter4)
# add_subdirectory(chapter5)
# add_subdirectory(chapter6)
# add_subdirectory(chapter7)
add_subdirectory(chapter8)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME}
  # Chapter1
  # Chapter2
  # Chapter3
  # Chapter4
  # Chapter5
  # Chapter6
  # Chapter7
  Chapter8
)