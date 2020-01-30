project (Tests)
cmake_minimum_required(VERSION 3.13.0)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Graph)

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
target_link_libraries(Tests
    PRIVATE
        Graph_lib
        GTest::GTest
        GTest::Main
)
