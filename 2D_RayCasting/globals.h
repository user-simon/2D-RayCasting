#pragma once
#include <SFML/Graphics.hpp>
#include "ray.h"
#include "wall.h"

constexpr auto TWO_PI = 3.14159265358979f * 2;
extern Vector2f g_mouse_pos;

inline int random(int max, int min = 0) { return rand() % (max - min) + min; }