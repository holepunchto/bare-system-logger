cmake_minimum_required(VERSION 4.0)

find_package(cmake-bare REQUIRED PATHS node_modules/cmake-bare)
find_package(cmake-fetch REQUIRED PATHS node_modules/cmake-fetch)

project(bare_system_logger C)

fetch_package("github:holepunchto/liblog#edcfd8f")

add_bare_module(bare_system_logger)

target_sources(
  ${bare_system_logger}
  PRIVATE
    binding.c
)

target_link_libraries(
  ${bare_system_logger}
  PRIVATE
    $<TARGET_OBJECTS:log>
  PUBLIC
    log
)
