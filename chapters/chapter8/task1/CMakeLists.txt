project(${PROJECT_NAME}Task1)

add_executable(${PROJECT_NAME}
  sources/Main.cpp
  sources/Point.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)