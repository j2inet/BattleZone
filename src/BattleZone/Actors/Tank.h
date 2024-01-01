#include "Actor.h"

class Tank : public Actor
{
	public : 
		Tank() : Actor() {
			this->Width = 3;
			this->Length = 3;
		};
		void Update() override 
		Tank(Position position) : Actor(position, 3, 3) {}
};