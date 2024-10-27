cmake_minimum_required(VERSION 3.5)
project(STACK_ARRAY VERSION 1.0 LANGUAGES CXX)

include_directories("include/")

include_directories(include)
add_compile_options(
  -Werror
  -Wall
  -Wextra
  -Wpedantic
  -Wcast-align
  -Wold-style-cast
  -Wredundant-decls
  -Wsign-conversion
  -Wsign-promo
  -std=c++23

  -O0
)

if (NOT CMAKE_CXX_EXTENSIONS)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

set(SOURCE_EXE src/main.cpp)
add_executable(TEST ${SOURCE_EXE})