#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Nodeq2
{
public:
	Nodeq2(float x, float y, sf::String name);
	~Nodeq2();

	float m_radius;
	bool highlight = false;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position;
	sf::CircleShape node;
	sf::Font m_font;
	sf::Text m_name;
	sf::String m_nameText;
private:

};
