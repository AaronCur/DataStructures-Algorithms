#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

class Button
{
public:
	Button();
	~Button();

	int m_buttonVal = 0.0f;
	bool switched = false;
	bool active = false;
	void update(sf::Time);
	void mouseDetection(sf::Vector2i mousePos, std::vector<std::string> sdest);
	void render(sf::RenderWindow &window);
	sf::Vector2f m_position;
	sf::RectangleShape button;
	sf::Font m_font;
	sf::Text m_name;
	sf::String m_button1;
	sf::String m_button2;

private:

};

