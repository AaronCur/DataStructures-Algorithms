#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Edge
{
public:
	Edge(float x, float y);
	~Edge();

	float m_radius;
	bool highlight = true;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position;
	sf::CircleShape node;
private:

};
