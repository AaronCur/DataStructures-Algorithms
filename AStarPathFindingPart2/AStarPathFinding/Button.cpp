#include "Button.h"
#include <iostream>
Button::Button() :
	m_position(800, 250),
	m_size(200,100),
	m_button1("Start"),
	m_button2("Reset")
{
	
	if (!m_font.loadFromFile("c:/windows/fonts/Adventure.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}

	m_name.setFont(m_font);
	m_name.setCharacterSize(40);

	
	
	
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
void Button::mouseDetection(sf::Vector2i mousePos)
{

		if ((m_position.x < mousePos.x) &&
			(m_position.x + m_size.x > mousePos.x) &&
			(m_position.y + m_size.y > mousePos.y) &&
			(m_position.y < mousePos.y))
		{
			if (m_buttonVal == 0 && selected == false)
			{
				m_buttonVal = 1;
				selected = true;
			}
			else if(m_buttonVal == 1 && selected == false)
			{
				m_buttonVal = 0;
				selected = true;
			}

		}
	
}



void Button::render(sf::RenderWindow &window)
{

	//window.draw(enemyRect);
	
	button.setFillColor(sf::Color(127, 127, 127));

	button.setOutlineThickness(5);
	button.setOutlineColor(sf::Color(0, 0, 0));
	button.setPosition(m_position);
	button.setSize(m_size);
	m_name.setPosition(m_position.x + (200 / 4), m_position.y + (100 / 4));
	m_name.setColor(sf::Color::White);
	window.draw(button);
	window.draw(m_name);


}