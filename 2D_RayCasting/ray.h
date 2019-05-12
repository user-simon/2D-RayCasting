#pragma once
#include "globals.h"
using namespace sf;

class ray
{
public:
	Vector2f m_end;

	ray() {};
	ray(float x, float y);
	void calc_hit(Vector2f wall1, Vector2f wall2);
	void reset();
private:
	int m_default_length;
	Vector2f m_direction;
};
