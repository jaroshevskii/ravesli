project(${PROJECT_NAME}Task4)

add_executable(${PROJECT_NAME}
  sources/Main.cpp
  sources/Card.cpp
  sources/Deck.cpp
  sources/Player.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)