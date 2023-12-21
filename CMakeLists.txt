cmake_minimum_required(VERSION 3.7)
project(codebase)

# Set normal compiler flags
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated -Wall")

# Set the project files
file(GLOB PROJECT_HEADERS "src/*.h")
file(GLOB PROJECT_SOURCES "src/*.c")

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Link SDL to the executable
target_link_libraries(${PROJECT_NAME})
