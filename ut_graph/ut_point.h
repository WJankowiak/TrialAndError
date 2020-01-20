#pragma once
#include<gtest/gtest.h>
#include"../Graph/Point.h""

class ut_point_test : public ::testing::Test {

};

TEST_F(ut_point_test, createObject) {
	Point p = Point();
	Point p2 = Point(1, 1);
}

TEST_F(ut_point_test, getPosition) {
	Point p = Point(3, 4);

	EXPECT_EQ(p.getX(), 3);
	EXPECT_EQ(p.getY(), 4);
}
