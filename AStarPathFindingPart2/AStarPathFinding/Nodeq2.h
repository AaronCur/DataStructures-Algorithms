#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Nodeq2
{
public:
	Nodeq2(float x, float y, sf::String name, sf::Font m_font);
	~Nodeq2();

	float m_radius;
	bool highlight = false;
	bool expand = false;
	bool selected = false;
	void update(sf::Time);
	void mouseDetection(sf::Vector2i mousePos, std::vector<std::string> sdest);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position;
	sf::CircleShape node;
	sf::Font m_font;
	sf::Text m_name;
	sf::String m_nameText;
private:

};
