#pragma once
#include "Actor.h"
#include "..\Math\Math.h"

class Block : public Actor
{
public: 
	Block() : Actor() {
		this->Width = 3;
		this->Height = 3;
	};

	void Upodate() override {}

	Block(Position position) : Actor(position, 3, 3) {}
};