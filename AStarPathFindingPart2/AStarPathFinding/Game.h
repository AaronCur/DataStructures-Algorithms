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
#include "Edge.h"
#include "Button.h"
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
	void runAstar();
	void resetAstar();
	void calculateHeuristic();

	void processGameEvents();
	//void NodeVisited(Node * node);

	// main window
	sf::RenderWindow m_window;

	sf::Font m_agentOrange;//font 
	sf::Font m_meatLoaf;
	sf::Font m_adventure;

	Nodeq2 *m_nodeq2;
	Edge *m_edge;
	Button *m_button;

	sf::Vector2i m_mousePos;

	//std::vector<Nodeq2 *> nodes;
	std::vector<Edge *> edges;
	std::vector<std::string> sdest;
	std::vector<Nodeq2 *> sdestnodes;
	std::map<std::string, int>nodeMap;

	bool active = false;

	sf::Font m_font;
	sf::CircleShape unexpandednode;
	sf::Text m_unexpanded;
	sf::String m_unexpandedText;

	sf::CircleShape expandednode;
	sf::Text m_expanded;
	sf::String m_expandedText;

	sf::CircleShape finalpathnode;
	sf::Text m_finalPath;
	sf::String m_pathText;

	sf::CircleShape startdestnode;
	sf::Text m_startDest;
	sf::String m_startDestText;


	
	

};

