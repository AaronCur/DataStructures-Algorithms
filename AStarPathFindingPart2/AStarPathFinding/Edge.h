#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Edge
{
public:
	Edge(float x1, float y1, float x2, float y2);
	~Edge();

	float m_radius;
	bool highlight = false;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position1; 
	sf::Vector2f m_position2;
	sf::Vertex line[2];
private:

};
