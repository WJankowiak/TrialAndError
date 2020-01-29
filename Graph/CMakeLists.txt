project (Graph)
cmake_minimum_required(VERSION 3.16.0)
add_library(Graph_lib Graph.cpp Graph.h )

target_sources(Graph_lib 
			PUBLIC
				Node.h
				Point.h
				euclideanDistance.h
				A_Star.h

			PRIVATE
	       		Node.cpp
	       		Point.cpp	
	    		euclideanDistance.cpp
	       		A_Star.cpp
	       		)