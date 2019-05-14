#include "globals.h"
using namespace sf;

Vector2f g_mouse_pos = Vector2f(0, 0);

int main()
{
	// Settings
	const float    ray_density = 1000;
	const Color    ray_color = Color(255, 255, 255, 10);
	const Color    wall_color = Color::Red;
	const Vector2f window_size(900, 900);

	// Initialize randomizer
	srand(time(NULL));

	// Make window
	RenderWindow window(VideoMode(window_size.x, window_size.y), "2D Ray Casting");

	// Make walls
	std::vector<wall> walls;
	for (int i = 0; i < 4; i++)
	{
		// Randomize start and end positions
		const Vector2f start(random(window_size.x), random(window_size.y));
		const Vector2f end(random(window_size.x), random(window_size.y));
		walls.push_back(wall(start, end));
	}

	// Make rays
	std::vector<ray> rays;
	const float step = 1.f / ray_density;
	for (float a = 0; a < TWO_PI; a += step)
	{
		const float x = cos(a);
		const float y = sin(a);
		rays.push_back(ray(x, y));
	}

	// Make line used for drawing rays
	VertexArray ray_line(Lines, 2);
	ray_line[0].color = ray_color;
	ray_line[1].color = ray_color;

	// Make line used for drawing walls
	VertexArray wall_line(Lines, 2);
	wall_line[0].color = wall_color;
	wall_line[1].color = wall_color;

	// Main loop
	Vector2f mouse_snapshot;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}	
		}

		// Re-randomize walls if key is pressed
		if (Keyboard::isKeyPressed(Keyboard::R) || Keyboard::isKeyPressed(Keyboard::Space))
		{
			for (int i = 0; i < walls.size(); i++)
			{
				walls[i].start = Vector2f(random(window_size.x), random(window_size.y));
				walls[i].end = Vector2f(random(window_size.x), random(window_size.y));
			}
			sleep(seconds(0.2));
		}

		// Update mouse pos
		g_mouse_pos = Vector2f(Mouse::getPosition(window));

		// If mouse if the same as previous frame, move on to the next
		if (mouse_snapshot == g_mouse_pos)
			continue;

		// Set start of ray-drawing line to mouse position
		ray_line[0].position = g_mouse_pos;

		window.clear();

		// Calculate intersections and draw rays
		for (int i = 0; i < rays.size(); i++)
		{
			// Set ray end-point to default
			rays[i].reset();

			// Cycle through every wall and set end point to intersection
			// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
			// between mouse and the new end-point. This means the ray will always go to the nearest wall
			for (int j = 0; j < walls.size(); j++)
			{
				// Calculate ray end-point
				rays[i].calc_hit(walls[j].start, walls[j].end);
			}
			
			// Set drawing-line end to final intersection
			ray_line[1].position = rays[i].m_end;
			
			// Draw ray
			window.draw(ray_line);
		}

		// Draw walls
		for (int i = 0; i < walls.size(); i++)
		{
			wall_line[0].position = walls[i].start;
			wall_line[1].position = walls[i].end;
			window.draw(wall_line);
		}

		// Update window
		window.display();

		// Save current mouse position
		mouse_snapshot = g_mouse_pos;
	}

	return 0;
}
