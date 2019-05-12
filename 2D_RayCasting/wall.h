#pragma once
#include "globals.h"

using namespace sf;
class wall
{
public:
	VertexArray line;
	wall() {};
	wall(Vector2f pos1, Vector2f pos2);
};

