#include "Button.h"
#include <iostream>
Button::Button() :
	m_position(500, 500)
{
	
	if (!m_font.loadFromFile("c:/windows/fonts/Adventure.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}

	m_name.setFont(m_font);
	m_name.setCharacterSize(15);
	
	
}

Button::~Button()
{

}

void Button::update(sf::Time t)
{
	switch (m_buttonVal)
	{
	case 0:
		m_name.setString(m_button1);
		m_name.setPosition(m_position.x + 5, m_position.y + 2);
		break;
	case 1:
		m_name.setString(m_button2);
		m_name.setPosition(m_position.x, m_position.y + 2);
		break;
	default:
		break;
	}
}
void Button::mouseDetection(sf::Vector2i mousePos, std::vector<std::string> sdest)
{
	if (sdest.size() < 2)
	{
		if ((m_position.x < mousePos.x) &&
			(m_position.x + m_radius > mousePos.x) &&
			(m_position.y + m_radius > mousePos.y) &&
			(m_position.y < mousePos.y))
		{
			selected = true;
		}
	}
}



void Button::render(sf::RenderWindow &window)
{

	//window.draw(enemyRect);
	sf::CircleShape node(m_radius);
	if (expand == false && highlight == false && selected == false)
	{
		node.setFillColor(sf::Color(127, 127, 127));
	}
	else if (expand == true && selected == false)
	{
		node.setFillColor(sf::Color(0, 249, 33, 200));
	}
	else if (selected == true && highlight == false)
	{
		node.setFillColor(sf::Color::Blue);
	}
	else if (selected == true && highlight == true)
	{
		node.setFillColor(sf::Color(249, 203, 0));
	}
	else
	{
		node.setFillColor(sf::Color::Red);
	}

	button.setFillColor(sf::Color(127, 127, 127));

	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color(0, 0, 0));
	button.setPosition(m_position);
	bu
	
	window.draw(button);
	window.draw(m_name);


}