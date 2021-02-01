add_executable(Server server.cpp)
add_executable(Client client.cpp)
target_link_libraries(Client common)
target_link_libraries(Server auto manager singer viewer Viewer_v common -pthread)
install(TARGETS	Server Client
RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)
