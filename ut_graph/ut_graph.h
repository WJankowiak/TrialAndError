#pragma once
#include "pch.h"

#include <Node.h>
#include <Graph.h>
#include <euclideanDistance.h>
namespace constant {

	const Node dummyNode1(1, Point(1,1));
	const Node dummyNode2(2, Point(3, 3));
}
class ut_graph_test : public ::testing::Test {
	
public:
	~ut_graph_test() = default;
	Graph g;
	void prepareTest() {
		g = Graph();
	}
	bool areDoubleSame(double dFirstVal, double dSecondVal)
	{
		return std::fabs(dFirstVal - dSecondVal) < 1E-3;
	}
};

TEST_F(ut_graph_test, addNodes) {
	prepareTest();
	g.addNode(Node(1));
}

TEST_F(ut_graph_test, checkNeighbourhoodSize) {
	//given
	prepareTest();

	//when
	g.addNode(constant::dummyNode1);
	g.addNode(constant::dummyNode2);
	g.setNeighbours(constant::dummyNode1, constant::dummyNode2);
}

TEST_F(ut_graph_test, setNeighbours) {
	prepareTest();

	g.addNode(constant::dummyNode1);
	g.addNode(constant::dummyNode2);
	EXPECT_TRUE(g.setNeighbours(constant::dummyNode1, constant::dummyNode2));
	
}

TEST_F(ut_graph_test, getDistance) {
	prepareTest();

	g.addNode(constant::dummyNode1);
	g.addNode(constant::dummyNode2);
	g.setNeighbours(1,2);

	EXPECT_TRUE(areDoubleSame(g.getNodesDistance(1, 2), 2.82843f));
}

TEST_F(ut_graph_test, areNodesNeighbours) {
	prepareTest();

	g.addNode(constant::dummyNode1);
	g.addNode(constant::dummyNode2);
	g.setNeighbours(constant::dummyNode1.getId(), constant::dummyNode2.getId());
	EXPECT_TRUE(g.isNeighbour(constant::dummyNode1, constant::dummyNode2));
}