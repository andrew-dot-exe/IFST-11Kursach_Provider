cmake_minimum_required(VERSION 3.6) 

project(IFST11Coursach)

set(SOURCES
    src/entities.cpp
    src/main.cpp
)
add_compile_options(-std=c++11 -stdlib=libc++)     `
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include
)
  