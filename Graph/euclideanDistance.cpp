#include "euclideanDistance.h"
#include <math.h>
double euclideanDistance::calculateDistance(const Point & p1, const Point & p2)
{
	double xs = pow(p1.getX() - p2.getX(), 2);
	double ys = pow(p1.getY() - p2.getY(), 2);

	return sqrt(xs + ys);
}
