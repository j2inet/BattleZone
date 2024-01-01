#pragma once

#include "Point.h"

struct Triangle
{
	union {
		struct {
			Point p1;
			Point p2;
			Point p3;
		};
		Point pointList[3];
	};
};


bool TriangleTriangleCollision(const Triangle& triangle1,
	const Triangle& triangle2,
	double eps = 0.0, bool allowReversed = true, bool onBoundary = true);