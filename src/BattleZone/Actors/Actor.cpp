#include <math.h>
#include "Actor.h"

void Actor::UpdateCorners()
{
	Point ux, uy;

	float halfWidth = Width / 2;
	float halfHeight = Height / 2;

	ux.x = cos(Position.Direction);
	ux.y = sin(Position.Direction);
	uy.x = -sin(Position.Direction);
	uy.y = cos(Position.Direction);
	
	corners[0] = Point{ halfWidth * ux.x + halfHeight * uy.x + Position.x, halfWidth * ux.y + halfHeight * uy.y + Position.y };
	corners[1] = Point{ -halfWidth * ux.x + halfHeight * uy.x + Position.x, -halfWidth * ux.y + halfHeight * uy.y + Position.y };
	corners[2] = Point{ halfWidth * ux.x + -halfHeight * uy.x + Position.x, halfWidth * ux.y + -halfHeight * uy.y + Position.y };
	corners[3] = Point{ -halfWidth * ux.x + -halfHeight * uy.x + Position.x, -halfWidth * ux.y + -halfHeight * uy.y + Position.y };
}