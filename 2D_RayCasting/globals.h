#pragma once
#include <SFML/Graphics.hpp>
#include "ray.h"
#include "wall.h"

constexpr auto PI = 3.14159265358979f;
extern Vector2f g_mouse_pos;

inline float degree_to_radian(double angle) { return (angle * PI) / 180; }
inline int random(int max, int min = 0) { return rand() % (max - min) + min; }