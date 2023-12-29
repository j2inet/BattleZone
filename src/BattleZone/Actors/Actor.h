
#include "..\Math\Math.h"

class Actor {
public:
	Actor() : ItemPosition(), Width(0), Height(0) {}
	Actor(Position position, float width, float height) : ItemPosition(position), Width(width), Height(height) {}


	inline const Position& GetPosition() const { return ItemPosition; }
	inline void SetPosition(const Position& position) { ItemPosition = position; }
	void UpdateCorners();
protected:

	Position ItemPosition;
	float  Width;
	float Height;
	Point corners[4];
};