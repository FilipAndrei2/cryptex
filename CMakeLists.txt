cmake_minimum_required(VERSION 3.31)
project(cryptex)

set(CMAKE_CXX_STANDARD 23)
file(GLOB CPP_SOURCES "src/cpp/*.cpp")

add_executable(cryptex ${CPP_SOURCES})
target_include_directories(cryptex PUBLIC ${PROJECT_SOURCE_DIR}/include)