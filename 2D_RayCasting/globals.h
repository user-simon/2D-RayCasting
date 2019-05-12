#pragma once
#include <SFML/Graphics.hpp>
#include "ray.h"
#include "wall.h"

constexpr auto PI = 3.14159265358979f;
extern Vector2f WINDOW_SIZE;
extern Vector2f g_mouse_pos;

inline double degree_to_radian(int angle) { return (angle * PI) / 180; }
inline double vec2_length(Vector2f p) { return sqrt(p.x * p.x + p.y * p.y); }
inline int random(int max, int min = 0) { return rand() % (max - min) + min; }
inline bool key_pressed(Keyboard::Key key) { return Keyboard::isKeyPressed(key); }