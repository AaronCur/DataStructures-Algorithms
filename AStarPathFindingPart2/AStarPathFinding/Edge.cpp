#include "Edge.h"
Edge::Edge(float x, float y) :
	m_position(x, y),
	m_radius(10.0f)
{
	//if (!enemyTxt.loadFromFile("resources/images/enemy.png"))
	//{
	//	std::string s("error loading texture from file");
	//	throw std::exception(s.c_str());
	//}


	//enemyRect.setTexture(&enemyTxt);
	//enemyRect.setTextureRect(animation.uvRect);
	//animation = Animation(&enemyTxt, sf::Vector2u(11, 4), 10.f);
	////animation.Update(3, 0.f);

}

Edge::~Edge()
{

}

void Edge::update(sf::Time t)
{


}

void Edge::render(sf::RenderWindow &window)
{

	//window.draw(enemyRect);
	sf::CircleShape node(m_radius);
	if (highlight == false)
	{

	}
	else
	{
		node.setFillColor(sf::Color::Red);
	}

	node.setOutlineThickness(3);
	node.setOutlineColor(sf::Color(127, 127, 127));
	node.setPosition(m_position);
	window.draw(node);


}