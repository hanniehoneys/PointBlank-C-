cmake_minimum_required(VERSION 3.0.0)
project(PointBlank.Auth)

file(GLOB INCLUDE_FILES
    *.hpp
    **/*.hpp
    **/**/*.hpp
    **/**/**/*.hpp
    **/**/**/**/*.hpp
)
file(GLOB SOURCE_FILES
    *.cpp
    **/*.cpp
    **/**/*.cpp
    **/**/**/*.cpp
    **/**/**/**/*.cpp
)

add_executable(${PROJECT_NAME} 
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    NOMINMAX
    WIN32_LEAN_AND_MEAN 
    _CRT_SECURE_NO_WARNINGS
    _WIN32_WINDOWS
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    PointBlank.Core
)