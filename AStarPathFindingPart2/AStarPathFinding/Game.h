#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include "Graph.h"
#include "Nodeq2.h"
#include <utility> // for STL pair



/// <summary>
/// @brief Main class for the projectO.R.B project.
/// author Aaron Curry
/// </summary>


class Game
{
public:
	Game();
	~Game();
	void run();

protected:
	void update(sf::Time time);
	void render();
	void processEvents();

	void processGameEvents();
	//void NodeVisited(Node * node);

	// main window
	sf::RenderWindow m_window;

	sf::Font m_agentOrange;//font 
	sf::Font m_meatLoaf;
	sf::Font m_adventure;

	Nodeq2 *m_nodeq2;

	std::vector<Nodeq2 *> nodes;

};
