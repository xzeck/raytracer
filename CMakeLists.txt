cmake_minimum_required (VERSION 3.5)
project (raytracer)

add_compile_options(-std=c++14)

include_directories(include)
add_executable(raytracer src/main.cpp)
set_target_properties(raytracer
                     PROPERTIES COMPILE_FLAGS "-g -Wall -Wextra")



target_link_libraries(raytracer)