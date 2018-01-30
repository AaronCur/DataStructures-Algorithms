#include "Nodeq2.h"
#include <iostream>
Nodeq2::Nodeq2(float x, float y, sf::String name) :
	m_position(x, y),
	m_radius(10.0f),
	m_nameText(name)
{
	//if (!enemyTxt.loadFromFile("resources/images/enemy.png"))
	//{
	//	std::string s("error loading texture from file");
	//	throw std::exception(s.c_str());
	//}
	if (!m_font.loadFromFile("c:/windows/fonts/Adventure.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}

	m_name.setFont(m_font);
	m_name.setCharacterSize(15);
	m_name.setString(m_nameText);
	//enemyRect.setTexture(&enemyTxt);
	//enemyRect.setTextureRect(animation.uvRect);
	//animation = Animation(&enemyTxt, sf::Vector2u(11, 4), 10.f);
	////animation.Update(3, 0.f);

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
			(m_position.x + m_radius > mousePos.x) &&
			(m_position.y + m_radius > mousePos.y) &&
			(m_position.y < mousePos.y))
		{
			selected = true;
		}
	}
}



void Nodeq2::render(sf::RenderWindow &window)
{

		//window.draw(enemyRect);
	sf::CircleShape node(m_radius);
	if (expand == false && highlight == false && selected == false)
	{
		node.setFillColor(sf::Color(127,127,127));
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
	
	node.setOutlineThickness(0);
	node.setOutlineColor(sf::Color(170, 170, 170));
	node.setPosition(m_position);
	m_name.setPosition(m_position.x + 5, m_position.y + 2);
	window.draw(node);
	window.draw(m_name);


}