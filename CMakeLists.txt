cmake_minimum_required(VERSION 3.23)

project(atay LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}
  src/main.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(copy_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/compile_commands.json"
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
        COMMENT "compile_commands.json in atay/ for local LSP detection"
    )
endif()
