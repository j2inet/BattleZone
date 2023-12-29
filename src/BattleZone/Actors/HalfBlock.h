#pragma once
#include "Block.h"


class HalfBlock : public Block
{
	HalfBlock() : Block() {
		this->Width = 3;
		this->Height = 3;
	};

	HalfBlock(Position position) : Block(position) {}
};