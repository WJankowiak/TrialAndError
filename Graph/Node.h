#pragma once
#include "Point.h"
class Node
{
	Point position;
	int id;

public:
	Node(int id);
	Point GetPosition();
	void setPosition(int x, int y);
	void setPosition(Point p);
	int getId;

};

