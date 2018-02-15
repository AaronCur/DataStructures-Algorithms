#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Nodeq2
{
public:
	Nodeq2(float x, float y);
	~Nodeq2();

	bool highlight = false;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position;

private:

};
