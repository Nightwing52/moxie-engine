cmake_minimum_required(VERSION 3.0)
project("moxie" LANGUAGES CXX VERSION 0.03)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
        ${INCLUDE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLM_INCLUDE_DIRS}
)

set(SOURCES
        Framework/stb_image.cpp
        Framework/Display.cpp
        Framework/Input.cpp
        Framework/Shader.cpp
        Framework/Mesh.cpp
        Framework/Texture.cpp
        Framework/Camera.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARIES}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib")
install(DIRECTORY "include" DESTINATION "include")
