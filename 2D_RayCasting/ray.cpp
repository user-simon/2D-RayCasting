#include "globals.h"
#include "ray.h"

ray::ray(float x, float y)
{
	// Default length is the distance from the mouse that the rays will be drawn and checked for intersections 
	// This is mostly arbitrary
	m_default_length = 3000;
	m_direction = Vector2f(x, y);
}

// Reset end-point of ray
void ray::reset()
{
	// Set end-point to (default length) distance away from mouse in set direction
	m_end = g_mouse_pos + m_direction * (float)m_default_length;
}

// Calculates intersection-point two lines
// Used for getting intersection between ray and wall
// More or less black-box code
void ray::calc_hit(Vector2f p3, Vector2f p4)
{
	const Vector2f p1 = g_mouse_pos;
	const Vector2f p2 = m_end;

	// Calculates denominator of equations
	const float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

	if (den == 0)
		return;

	const float t =  ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
	const float u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;

	if (t > 0 && t < 1 && u > 0 && u < 1)
	{
		// Gets intersection point
		m_end.x = p1.x + t * (p2.x - p1.x);
		m_end.y = p1.y + t * (p2.y - p1.y);
	}
}
