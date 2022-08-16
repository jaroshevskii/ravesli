project(${PROJECT_NAME}Task)

add_executable(${PROJECT_NAME}
  sources/Main.cpp
  sources/Point3D.cpp
  sources/Vector3D.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE 
    include
)