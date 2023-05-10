cmake_minimum_required(VERSION 3.0.0)
project(PointBlank.Core LANGUAGES CXX)

file(GLOB INCLUDE_FILES
    *.hpp
    **/*.hpp
    **/**/*.hpp
)
file(GLOB SOURCE_FILES
    *.cpp
    **/*.cpp
    **/**/*.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${INCLUDE_FILES}
    ${SOURCE_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 11
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    _WIN32_WINNT=0x0601
)

find_package(Boost REQUIRED)
find_package(RapidJSON REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(magic_enum REQUIRED)
find_package(unofficial-libmariadb REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME} PUBLIC
    ${Boost_LIBRARIES}
    rapidjson
    OpenSSL::SSL OpenSSL::Crypto
    magic_enum::magic_enum
    unofficial::libmariadb
    sqlpp11::sqlpp11
)