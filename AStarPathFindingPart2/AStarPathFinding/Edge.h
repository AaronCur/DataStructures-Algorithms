#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Edge
{
public:
	Edge(int weight,float x1, float y1, float x2, float y2, sf::Font font);
	~Edge();

	float m_radius;
	bool highlight = false;
	void update(sf::Time t);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position1; 
	sf::Vector2f m_position2;
	sf::Vector2f m_weightPosition;

	sf::Vertex line[2];
	sf::Font m_font;
	sf::Text m_weight;
	sf::String m_weightText;
private:

};
