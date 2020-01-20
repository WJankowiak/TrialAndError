#include "pch.h"
#include "Graph.h"
#include <gtest/gtest.h>

#include "ut_node.h"
#include "ut_graph.h"
#include "ut_point.h"
#include "ut_A_Star.h"
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}