cmake_minimum_required(VERSION 3.10)

project(miochat-server C)

set(SRC_DIR src)
set(INCLUDE_DIR include)

include_directories(${INCLUDE_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

file(GLOB SRCS "${SRC_DIR}/*.c")

add_executable(miochat-server ${SRCS})

install(TARGETS miochat-server DESTINATION /usr/local/bin)

add_custom_target(clean-all
  COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
  COMMENT "Cleaning build directory"
)
