add_library(auto STATIC
	auto.cpp
)
add_library(manager STATIC
	manager.cpp
)
add_library(singer STATIC
	singer.cpp
)
add_library(Viewer_v STATIC
	Viewer_v.cpp
)

add_library(common STATIC
	common.cpp
)

add_library(viewer STATIC
	viewer.cpp
)


install(TARGETS auto manager singer viewer
ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)
