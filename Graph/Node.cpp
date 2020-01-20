#include "Node.h"
#include "euclideanDistance.h"
int Node::getId() const{
	return id;
}

double Node::calculateDistance(Node n) const
{
	return euclideanDistance::calculateDistance(position, n.getPosition());
}

Node::Node(int i) {
	id = i;
}

Node::Node(int i, const Point p) {
	id = i;
	position = p;
}

void Node::setPosition(Point p)  {
	position = p;
}

Point Node::getPosition() const {
	return position;
}