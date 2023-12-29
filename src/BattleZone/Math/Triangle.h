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