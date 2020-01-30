project (Graph)
cmake_minimum_required(VERSION 3.13.0)
add_library(Graph_lib Graph.cpp Graph.h )

target_sources(Graph_lib 
			PRIVATE
	       		Node.cpp
	       		Point.cpp	
	    		euclideanDistance.cpp
				A_Star.cpp
				Node.h
				Point.h
				euclideanDistance.h
				A_Star.h
			 )
			 
target_include_directories(Graph_lib
	PUBLIC
	${PROJECT_SOURCE_DIR}
)

target_compile_features(Graph_lib
	PUBLIC
		cxx_std_17
)
