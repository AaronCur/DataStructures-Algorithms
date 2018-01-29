#include "Edge.h"
Edge::Edge(float x1, float y1,float x2, float y2) :
	m_position1(x1, y1),
	m_position2(x2,y2)
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
	line[0].position = m_position1;
	line[1].position = m_position2;
	if (highlight == false)
	{
		line[0].color = sf::Color(127,127,127);
		line[1].color = sf::Color(127, 127, 127);

	}
	else
	{
		node.setFillColor(sf::Color::Red);
		line[0].color = sf::Color::Red;
		line[1].color = sf::Color::Red;
	}

	window.draw(line,2,sf::Lines);



}