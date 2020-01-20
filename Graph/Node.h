#pragma once
#include "Point.h"
class Node
{
	Point position;
	int id;

public:
	Node(int id);
	Node(int id, const Point p);
	~Node() = default;
	Point getPosition() const;
	void setPosition(int x, int y);
	void setPosition(Point p);
	int getId() const;
	double calculateDistance(Node n) const;
	bool operator==(const Node n1) const {
		return id == n1.getId();
	}

};

