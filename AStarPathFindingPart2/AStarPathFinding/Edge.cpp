#include "Edge.h"
#include <iostream>

Edge::Edge(int weight,float x1, float y1,float x2, float y2, sf::Font font) :
	m_position1(x1, y1),
	m_position2(x2,y2),
	m_font(font)

{
	
	m_weightText = std::to_string(weight);
	m_weight.setFont(m_font);
	m_weight.setCharacterSize(18.5);
	m_weight.setString(m_weightText);
	m_weight.setColor(sf::Color::Black);

	m_weightPosition = sf::Vector2f((x1 + x2) / 2, (y1 + y2) / 2);

}

Edge::~Edge()
{

}

void Edge::update(sf::Time t)
{


}

void Edge::render(sf::RenderWindow &window)
{
	m_weight.setPosition(m_weightPosition);
	line[0].position = m_position1;
	line[1].position = m_position2;
	if (highlight == false)
	{
		line[0].color = sf::Color(127,127,127);
		line[1].color = sf::Color(127, 127, 127);

	}
	else
	{
		line[0].color = sf::Color::Red;
		line[1].color = sf::Color::Red;
	}

	window.draw(line,2,sf::Lines);
	window.draw(m_weight);




}