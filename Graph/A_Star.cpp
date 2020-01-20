#include "A_Star.h"
#include <list>
std::vector<Node> A_Star::getPath(const Node& from, const Node& to, const Graph& g)
{
	std::list<Node> openSet{};
	openSet.push_back(from);	
	int numberOfNodes = g.getNodes().size();
	int*cameFrom = new int[numberOfNodes+1];
	std::vector < double> gScore = std::vector<double>(numberOfNodes+1);
	std::vector < double> fScore = std::vector<double>(numberOfNodes+1);
	for (int i = 0; i < numberOfNodes; i++) {
		cameFrom[i] = -1;
		gScore[i] = INT_MAX;
	}
	gScore[from.getId()] = 0;
	fScore[from.getId()] = from.calculateDistance(to);
	while (!openSet.size() == 0) {
		auto current = getCheapestNode(openSet, fScore,numberOfNodes);
		if (current.getId() == to.getId())
			return reconstructPath(cameFrom, from, current, g);
		openSet.remove(current);
		for (Node& n : g.getNodes()) {
			if (g.isNeighbour(n, current)) {
				double tempScore = gScore[current.getId()] + current.calculateDistance(n);
				if (tempScore < gScore[n.getId()]) {
					cameFrom[n.getId()] = current.getId();
					gScore[n.getId()] = tempScore;	
					fScore[n.getId()] = gScore[n.getId()] + n.calculateDistance(to);
					if (!contains(openSet, n))
						openSet.push_back(n);
				}
			}
		}
	}
	return std::vector<Node>{};
}

Node A_Star::getCheapestNode(std::list<Node> openSet, std::vector < double> fScore, int numberOfNodes)
{	
	double minValue = INT_MAX;
	double index = -1;
	for (int i = 0; i < numberOfNodes; i++) {
		if (fScore[i] < minValue) {
			if (containsIndex(openSet, i)) {
				minValue = fScore[i];
				index = i;
			}
		}
	}
	Node returnNode = NULL;
	for (Node& n : openSet) {
		if (n.getId() == index) {
			returnNode = n;
		}
	}
	return returnNode;
}

bool A_Star::containsIndex(std::list<Node> openSet, int index)
{
	for (Node& n : openSet) {
		if (n.getId() == index)
			return true;
	}
	return false;
}

bool A_Star::contains(std::list<Node> openSet, Node & n1)
{
	bool result = false;
	for (Node& n : openSet) {
		if (n.getId() == n1.getId())
			result = true;
	}
	return result;
}

std::vector<Node> A_Star::reconstructPath(int * cameFrom, const Node& start, Node & current, const Graph & g) {
	std::vector<Node> nodes{};
	int  index = current.getId();
	while (index != start.getId()) {
		nodes.push_back(g.getNode(cameFrom[index]));
		index = cameFrom[index];
	}
	return nodes;
}