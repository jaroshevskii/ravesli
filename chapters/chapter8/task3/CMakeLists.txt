project(${PROJECT_NAME}Task3)

add_executable(${PROJECT_NAME}
  sources/Main.cpp
  sources/Monster.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)