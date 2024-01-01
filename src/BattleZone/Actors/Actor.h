
#include "..\Math\Math.h"

class Actor {
public:

	Actor() : ItemPosition(), Width(0), Length(0) {}
	Actor(Position position, float width, float height) : ItemPosition(position), Width(width), Length(height) {}
	virtual void Update() = 0;
	bool HasOverlap(const Actor& other) const;


	inline const Position& GetPosition() const { return ItemPosition; }
	inline void SetPosition(const Position& position) { ItemPosition = position; UpdateCorners(); }
	inline void SetProposedPosition(const Position& position) { ProposedPosition = position; proposingPosition = true; }
	inline void CommitPosition() { ItemPosition = ProposedPosition; proposingPosition = false; UpdateCorners(); }
	inline void RevertPosition() { proposingPosition = false; }

	void UpdateCorners();
protected:

	Position ItemPosition, ProposedPosition;
	bool proposingPosition;
	float  Width;
	float Length;
	bool collisionEnabled = true;

	Point corners[4];
};