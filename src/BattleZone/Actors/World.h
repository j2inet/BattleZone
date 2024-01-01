#include <vector>
#include <memory>
#include "../Math/Math.h"
#include "Actor.h"
#include "Block.h"
#include "HalfBlock.h"
#include "Missle.h"
#include "Pyramid.h"
#include "Tank.h"


class World
{
public:
	World();
	~World();
	void Update();
	void Draw();
	void AddActor(std::shared_ptr<Actor> actor);
	void RemoveActor(std::shared_ptr<Actor> actor);
private:
	std::vector<std::shared_ptr<Actor> > actorList;
	std::shared_ptr<Actor> player;

};
