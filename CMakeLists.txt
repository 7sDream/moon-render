cmake_minimum_required(VERSION 3.15)
project(moon-render C)

set(CMAKE_C_STANDARD 11)

find_package(Freetype 2 REQUIRED)

add_executable(moon-render main.c)

target_link_libraries(moon-render ${FREETYPE_LIBRARIES})
target_include_directories(moon-render PRIVATE ${FREETYPE_INCLUDE_DIRS})

get_target_property(includes moon-render INCLUDE_DIRECTORIES)
foreach(include ${includes})
    message(STATUS "include: '${include}'")
endforeach()

get_target_property(libraries moon-render LINK_LIBRARIES)
foreach(library ${libraries})
    message(STATUS "link: '${library}'")
endforeach()
