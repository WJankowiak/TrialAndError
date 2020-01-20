#pragma once
class Point
{
	int x_pos;
	int y_pos;

public :
	Point();
	~Point() = default;
	Point(int x, int y);
	bool operator == (const Point p) const {
		return x_pos == p.x_pos && y_pos == p.y_pos;
	}
	int getX() const { return x_pos; }
	int getY() const { return y_pos; }
};

