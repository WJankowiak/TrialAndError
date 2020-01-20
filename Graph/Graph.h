#pragma once
#include <list>
#include <vector>
#include <algorithm>
#include "Node.h"
class Graph
{
private :

	std::vector<Node> nodes;
	std::vector<std::vector<double>>  neighbourhood;

public:
	Graph() = default;
	~Graph() = default;
	void addNode(Node N);
	bool setNeighbours(const Node n1, const Node n2);
	bool setNeighbours(const int id1, const int id2);
	bool isNodePresent(int id) const;
	bool isNeighbour(const Node n1, const Node n2) const;
	Node getNode(const int id) const;
	double getNodesDistance(const int id1, const int id2);
	std::vector<Node> getNodes() const;

};

