#include <math.h>
#include "../Math/Position.h"
#include "Actor.h"

void Actor::UpdateCorners()
{
	Point ux, uy;

	float halfWidth = Width / 2;
	float halfHeight = Height / 2;

	ux.x = cos(ItemPosition.Direction);
	ux.y = sin(ItemPosition.Direction);
	uy.x = -sin(ItemPosition.Direction);
	uy.y = cos(ItemPosition.Direction);
	
	corners[0] = Point{ halfWidth * ux.x + halfHeight * uy.x + ItemPosition.x, halfWidth * ux.y + halfHeight * uy.y + ItemPosition.y };
	corners[1] = Point{ -halfWidth * ux.x + halfHeight * uy.x + ItemPosition.x, -halfWidth * ux.y + halfHeight * uy.y + ItemPosition.y };
	corners[2] = Point{ halfWidth * ux.x + -halfHeight * uy.x + ItemPosition.x, halfWidth * ux.y + -halfHeight * uy.y + ItemPosition.y };
	corners[3] = Point{ -halfWidth * ux.x + -halfHeight * uy.x + ItemPosition.x, -halfWidth * ux.y + -halfHeight * uy.y + ItemPosition.y };
}