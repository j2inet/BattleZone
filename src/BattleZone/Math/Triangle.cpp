#include "Triangle.h"


inline float sign(Point p1, Point p2, Point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool pointInTriangle(Point pt, Triangle tri)
{
	float d1, d2, d3;
	bool has_neg, has_pos;
	d1 = sign(pt, tri.pointList[0], tri.pointList[1]);
	d2 = sign(pt, tri.pointList[1], tri.pointList[2]);
	d3 = sign(pt, tri.pointList[2], tri.pointList[0]);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(has_neg && has_pos);
}

inline double Det2D(const Triangle& triangle)
{
	return +triangle.p1.x * (triangle.p2.y - triangle.p3.y)
		+ triangle.p2.x * (triangle.p3.y - triangle.p1.y)
		+ triangle.p3.x * (triangle.p1.y - triangle.p2.y);
}

void CheckTriWinding(const Triangle t, bool allowReversed = true)
{
	double detTri = Det2D(t);
	[[unlikely]]
	if (detTri < 0.0)
	{
		if (allowReversed)
		{
			Triangle tReverse = t;
			tReverse.p1 = t.p3;
			tReverse.p3 = t.p1;
			tReverse.p2 = t.p2;
			return CheckTriWinding(tReverse, false);
		}
		else throw std::runtime_error("triangle has wrong winding direction");
	}
}

bool BoundaryCollideChk(const Triangle& t, double eps)
{
	return Det2D(t) < eps;
}

bool BoundaryCollideChk(const Point& p1, const Point& p2, const Point& p3, double eps)
{
	Triangle t = { {{p1, p2, p3}} };
	return BoundaryCollideChk(t, eps);

}

bool BoundaryDoesntCollideChk(const Triangle& t, double eps)
{
	return Det2D(t) <= eps;
}

bool BoundaryDoesntCollideChk(const Point& p1, const Point& p2, const Point& p3, double eps)
{
	Triangle t = { {{p1, p2, p3}} };
	return BoundaryDoesntCollideChk(t, eps);
}



bool TriangleTriangleCollision(const Triangle& triangle1,
	const Triangle& triangle2,
	double eps = 0.0, bool allowReversed = true, bool onBoundary = true)
{
	//Trangles must be expressed anti-clockwise
	CheckTriWinding(triangle1, allowReversed);
	CheckTriWinding(triangle2, allowReversed);

	//For edge E of trangle 1,
	for (int i = 0; i < 3; i++)
	{
		int j = (i + 1) % 3;
		[[likely]]
		if (onBoundary)
		{

			//Check all points of trangle 2 lay on the external side of the edge E. If
			//they do, the triangles do not collide.
			if (BoundaryCollideChk(triangle1.pointList[i], triangle1.pointList[j], triangle2.pointList[0], eps) &&
				BoundaryCollideChk(triangle1.pointList[i], triangle1.pointList[j], triangle2.pointList[1], eps) &&
				BoundaryCollideChk(triangle1.pointList[i], triangle1.pointList[j], triangle2.pointList[2], eps))
				return false;
		}
		else
		{
			if (BoundaryDoesntCollideChk(triangle1.pointList[i], triangle1.pointList[j], triangle2.pointList[0], eps) &&
				BoundaryDoesntCollideChk(triangle1.pointList[i], triangle1.pointList[j], triangle2.pointList[1], eps) &&
				BoundaryDoesntCollideChk(triangle1.pointList[i], triangle1.pointList[j], triangle2.pointList[2], eps))
				return false;
		}

		if (onBoundary)
		{

			//Check all points of trangle 2 lay on the external side of the edge E. If
			//they do, the triangles do not collide.
			if (BoundaryCollideChk(triangle2.pointList[i], triangle2.pointList[j], triangle1.pointList[0], eps) &&
				BoundaryCollideChk(triangle2.pointList[i], triangle2.pointList[j], triangle1.pointList[1], eps) &&
				BoundaryCollideChk(triangle2.pointList[i], triangle2.pointList[j], triangle1.pointList[2], eps))
				return false;
		}
		else
		{
			if (BoundaryDoesntCollideChk(triangle2.pointList[i], triangle2.pointList[j], triangle1.pointList[0], eps) &&
				BoundaryDoesntCollideChk(triangle2.pointList[i], triangle2.pointList[j], triangle1.pointList[1], eps) &&
				BoundaryDoesntCollideChk(triangle2.pointList[i], triangle2.pointList[j], triangle1.pointList[2], eps))
				return false;
		}
	}
	//The triangles collide
	return true;
}