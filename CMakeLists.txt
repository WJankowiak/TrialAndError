project (Tests)
cmake_minimum_required(VERSION 3.16.0)

add_subdirectory(Graph)
add_subdirectory(googletest)

add_executable(Tests ut_graph/main.cpp)

target_sources(Tests 
            PRIVATE
                ut_graph/pch.cpp
                ut_graph/pch.h
                ut_graph/ut_A_Star.h
                ut_graph/ut_graph.h
                ut_graph/ut_node.h
                ut_graph/ut_point.h
                )
target_link_libraries(Tests Graph_lib)
target_link_libraries(Tests googletest)

target_include_directories(Tests PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Graph"
                          "${PROJECT_SOURCE_DIR}/googletest"
                          )
