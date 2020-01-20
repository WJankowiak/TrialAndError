#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include <Graph.h>
#include <A_Star.h>
class ut_A_Star : public ::testing::Test {
public:
	Graph g;
	void prepareGraph() {
		g.addNode(Node(1,Point(1,1)));
		g.addNode(Node(2, Point(1, 4)));
		g.addNode(Node(3, Point(7, 9)));
		g.addNode(Node(4, Point(20, 15)));
		g.addNode(Node(5, Point(13, 11)));
		g.addNode(Node(6, Point(10, 1)));
		g.addNode(Node(7, Point(122, 11)));
		g.addNode(Node(8, Point(176, 761)));
		g.setNeighbours(1, 4);
		g.setNeighbours(1, 3);
		g.setNeighbours(1, 8);
		g.setNeighbours(2, 4);
		g.setNeighbours(2, 5);
		g.setNeighbours(2, 6);
		g.setNeighbours(8, 5);
		g.setNeighbours(8, 4);
		g.setNeighbours(6, 7);
		g.setNeighbours(6, 3);
	}
};
TEST_F(ut_A_Star, algorithm_finds_ok_path) {
	prepareGraph();
	EXPECT_EQ(A_Star::getPath(g.getNode(1), g.getNode(7), g).size(), 3);

}