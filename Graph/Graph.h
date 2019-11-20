#pragma once
#include <list>
#include "Node.h"
class Graph
{
private :

public:
	Graph() = default;
	~Graph() = default;
	std::list<Node>getNeighbours(Node n);
};

