#include "Graph.h"
#include <algorithm>
#include "euclideanDistance.h"

void Graph::addNode(Node n) {
	nodes.push_back(n);

	if (neighbourhood.size() < n.getId() + 1.0 ) {
		int newSize = n.getId() + 1;
		neighbourhood.resize(newSize, std::vector<double>());
		for (int i = 0; i < neighbourhood.size(); i++) {
			neighbourhood.at(i).resize(newSize, -1);
		}
	}
}

bool Graph::setNeighbours(const Node n1, const Node n2) {

	if (isNodePresent(n1.getId()) && isNodePresent(n2.getId())) {
		double distance = n1.calculateDistance(n2);
		neighbourhood.at(n1.getId()).at(n2.getId()) = distance;
		neighbourhood.at(n2.getId()).at(n1.getId()) = distance;

		return true;
	}
	return false;
}

bool Graph::setNeighbours(const int id1, const int id2)
{
	if (isNodePresent(id1) && isNodePresent(id2)) {
		double distance = getNode(id1).calculateDistance(getNode(id2));
		neighbourhood.at(id1).at(id2) = distance;
		neighbourhood.at(id2).at(id1) = distance;
		return true;
	}

	return false;
}

bool Graph::isNodePresent(int id) const
{
	return std::find_if(std::begin(nodes),std::end(nodes), [=](const Node & p) { return p.getId() == id; }) != nodes.end();
}

bool Graph::isNeighbour(const Node n1, const Node n2) const
{
	return neighbourhood.at(n1.getId()).at(n2.getId())!=-1;
}

Node Graph::getNode(const int id) const
{
	if(isNodePresent(id))
		return nodes.at(id-1);
	return Node(-1,Point(-1,-1));
}

double Graph::getNodesDistance(const int id1, const int id2)
{
	return neighbourhood.at(id1).at(id2);
}

std::vector<Node> Graph::getNodes() const
{
	return nodes;
}
