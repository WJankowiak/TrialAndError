#pragma once
#include "Node.h"
#include "Graph.h"
#include <list>
namespace A_Star
{
	std::vector<Node> getPath(const Node& from, const Node& to, const Graph& g);
	static Node getCheapestNode(std::list <Node> openSet, std::vector < double> fScore, int numberOfNodes);
	static bool containsIndex(std::list <Node> openSet, int index);
	static bool contains(std::list<Node> openSet, Node & n);
	std::vector<Node> reconstructPath(int* cameFrom, const Node& start, Node& current, const Graph& g);
}; //A_Star

