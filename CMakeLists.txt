cmake_minimum_required(VERSION 3.10)

option(build "Build code." ON)
option(ut "Build all tests." ON)

project(Proj)

set(CMAKE_CXX_FLAGS "-g -Wall -Werror -Wno-missing-braces")
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_SRC src)
file(GLOB_RECURSE sources
  ${PROJECT_SRC}/*.cpp
)

if (build)
  include_directories(
    ${PROJECT_SRC}
  )
  add_executable(build
    src/main.cpp
    ${sources}
  )
endif()

if (ut)
  add_library(sources ${sources})
  add_subdirectory(lib/gtest-1.8.0)
  enable_testing()
  include_directories(
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
  )

  set(TEST_DIR tests/)
  file(GLOB_RECURSE test_sources ${TEST_DIR}/*.cpp)
  add_executable(ut ${test_sources})

  target_link_libraries(ut
    gtest
    gtest_main
    sources
  )

  add_test(NAME sum COMMAND ut)
endif()
