#include "wall.h"

wall::wall(Vector2f pos1, Vector2f pos2)
{
	line = VertexArray(Lines, 2);

	line[0].position = pos1;
	line[1].position = pos2;
}