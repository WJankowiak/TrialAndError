#pragma once
#include "pch.h"
#include <gtest/gtest.h>
#include "Node.h"

#include <math.h>
namespace constant {
	const int dummyId = 1;
	const Point dummyPoint = Point(1, 1);
}
class ut_node_test : public ::testing::Test
{
public:
	bool areDoubleSame(double dFirstVal, double dSecondVal)
	{
		return std::fabs(dFirstVal - dSecondVal) < 1E-3;
	}
};

TEST_F(ut_node_test, createObject) {
	Node n = Node(constant::dummyId);
}

TEST_F(ut_node_test, isNodeIdSet) {
	Node n = Node(constant::dummyId);
	EXPECT_EQ(n.getId(), constant::dummyId);
}

TEST_F(ut_node_test, isPositionSet) {
	Node n = Node(constant::dummyId);
	n.setPosition(constant::dummyPoint);
	EXPECT_EQ(n.getPosition(), constant::dummyPoint);
}

TEST_F(ut_node_test, calculateDistance) {
	Node n1 = Node(constant::dummyId, constant::dummyPoint);
	Node n2 = Node(2, Point(10, 10));
	n1.calculateDistance(n2);
	EXPECT_TRUE(areDoubleSame(n1.calculateDistance(n2), 12.7279f));
}