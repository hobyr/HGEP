cmake_minimum_required(VERSION 3.16)

# set the project name
project(FantasticEngine VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# create compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# do not compile unrelated GLFW stuff
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# add GLFW library
add_subdirectory(Dependencies/GLFW)
add_subdirectory(Dependencies/GLAD)

# copy files for execution
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/shader.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/shader.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# add the executable
add_executable(FantasticEngine 
    src/main.cpp
    src/shader.cpp
    )

# link libraries to executable
target_link_libraries(FantasticEngine 
    PUBLIC 
        glfw 
        glad
    )

# adding includes for compiler
target_include_directories(FantasticEngine PUBLIC
                    "Dependencies/GLAD/include"
                    "Dependencies/GLFW/include")
