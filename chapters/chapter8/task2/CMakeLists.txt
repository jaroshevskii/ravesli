project(${PROJECT_NAME}Task2)

add_executable(${PROJECT_NAME}
  sources/Main.cpp
  sources/Welcome.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)