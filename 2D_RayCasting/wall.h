#pragma once
#include "globals.h"

using namespace sf;
class wall
{
public:
	Vector2f start;
	Vector2f end;
	wall() {};
	wall(Vector2f pos1, Vector2f pos2);
};

