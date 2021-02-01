project(Server)
project(Client)
cmake_minimum_required(VERSION 3.10)

include_directories(inc)
add_subdirectory(lib)
add_subdirectory(src)

add_dependencies(Server auto manager singer viewer Viewer_v common -pthread)
add_dependencies(Client common)
