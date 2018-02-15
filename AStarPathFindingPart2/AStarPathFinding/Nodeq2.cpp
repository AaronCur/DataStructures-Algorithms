#include "Nodeq2.h"
#include <iostream>
Nodeq2::Nodeq2(float x, float y, sf::String name, sf::Font font) :
	m_position(x, y),
	m_radius(10.0f),
	m_nameText(name),
	m_font(font),
	m_heuristic(0)
{


	m_name.setFont(m_font);
	m_name.setCharacterSize(18);
	m_name.setString(m_nameText);

	m_heuristictext.setFont(m_font);
	m_heuristictext.setCharacterSize(18);
	m_heuristictext.setPosition(m_position.x + 3, m_position.y + 30);
	m_heuristictext.setColor(sf::Color::Blue);
	

}

Nodeq2::~Nodeq2()
{

}

void Nodeq2::update(sf::Time t)
{
	
	

	if (highlight == true)
	{
		expand = false;
		//selected = false;
	}
}
void Nodeq2::mouseDetection(sf::Vector2i mousePos, std::vector<std::string> sdest)
{
	if (sdest.size() < 2)
	{
		if ((m_position.x < mousePos.x) &&
			(m_position.x + (m_radius * 2) > mousePos.x) &&
			(m_position.y + (m_radius * 2) > mousePos.y) &&
			(m_position.y < mousePos.y))
		{
			selected = true;
		}
	}
}



void Nodeq2::render(sf::RenderWindow &window)
{
	m_heuristictext.setString(std::to_string((int)m_heuristic));

	node.setRadius(m_radius);
	if (expand == false && highlight == false && selected == false)
	{
		node.setFillColor(sf::Color(127, 127, 127));
	}
	else if (expand == true && selected == false)
	{
		node.setFillColor(sf::Color(0, 249, 33 ));
	}
	else if (selected == true && highlight == false)
	{
		node.setFillColor(sf::Color(249, 203, 0));
	}
	else if (selected == true && highlight == true)
	{
		node.setFillColor(sf::Color(249, 203, 0));
	}
	else 
	{
		node.setFillColor(sf::Color::Red);
	}
	
	node.setOutlineThickness(4);
	node.setOutlineColor(sf::Color(0, 0, 0));
	node.setPosition(m_position);
	m_name.setPosition(m_position.x + 5, m_position.y + 2);
	window.draw(node);
	window.draw(m_name);
	window.draw(m_heuristictext);


}