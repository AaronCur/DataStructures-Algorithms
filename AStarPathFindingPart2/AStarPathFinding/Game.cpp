#include "SFML/Audio.hpp"
#include "Game.h"
#include <cmath> 
#include <math.h>
Graph<pair<string, int>, int > myGraph(30);

Graph<std::string, int> graph(25);

static double const MS_PER_UPDATE = 10.0;

using std::pair;

using namespace std;

std::vector<Nodeq2 *> nodes;

std::vector<Nodeq2 *> startdest;




typedef GraphArc<std::pair<std::string, int>, int> Arc;
typedef GraphNode<std::pair<std::string, int>, int> Node;

void visit(Node * node) {
	cout << "Visiting: " << node->data().first << endl;

	std::string temp = node->data().first;

	for (int i = 0; i < nodes.size(); i++)
	{
		std::string temp2 = nodes[i]->m_nameText;
		if (temp2 == temp)
		{
			nodes[i]->expand = true;
		}

	}
	
}
void passHeuristic(Node * node) {

	std::string temp = node->data().first;

	for (int i = 0; i < nodes.size(); i++)
	{
		std::string temp2 = nodes[i]->m_nameText;
		if (temp2 == temp)
		{
			node->m_heuristic = nodes[i]->m_heuristic;
		}

	}

}

Game::Game() :
	m_window(sf::VideoMode(1280, 720, 32), "AstarProject")
{
	
	if (!m_font.loadFromFile("c:/windows/fonts/Adventure.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}

	m_button = new Button(m_font);

	unexpandednode.setFillColor(sf::Color(127, 127, 127));
	unexpandednode.setRadius(6.0f);
	unexpandednode.setOutlineThickness(4);
	unexpandednode.setOutlineColor(sf::Color(0, 0, 0));
	unexpandednode.setPosition(100, 550);

	m_unexpanded.setFont(m_font);
	m_unexpanded.setCharacterSize(22);
	m_unexpanded.setString(" - Unexpanded Node");
	m_unexpanded.setPosition(130, 550);
	m_unexpanded.setColor(sf::Color::Black);

	startdestnode.setFillColor(sf::Color(249, 203, 0));;
	startdestnode.setRadius(6.0f);
	startdestnode.setOutlineThickness(4);
	startdestnode.setOutlineColor(sf::Color(0, 0, 0));
	startdestnode.setPosition(100, 580);

	m_startDest.setFont(m_font);
	m_startDest.setCharacterSize(22);
	m_startDest.setString(" - Start/ Destination Node");
	m_startDest.setPosition(130, 580);
	m_startDest.setColor(sf::Color::Black);

	expandednode.setFillColor(sf::Color(0, 249, 33));
	expandednode.setRadius(6.0f);
	expandednode.setOutlineThickness(4);
	expandednode.setOutlineColor(sf::Color(0, 0, 0));
	expandednode.setPosition(100, 610);

	m_expanded.setFont(m_font);
	m_expanded.setCharacterSize(22);
	m_expanded.setString(" - Expanded Node");
	m_expanded.setPosition(130, 610);
	m_expanded.setColor(sf::Color::Black);

	finalpathnode.setFillColor(sf::Color::Red);
	finalpathnode.setRadius(6.0f);
	finalpathnode.setOutlineThickness(4);
	finalpathnode.setOutlineColor(sf::Color(0, 0, 0));
	finalpathnode.setPosition(100, 640);

	m_finalPath.setFont(m_font);
	m_finalPath.setCharacterSize(22);
	m_finalPath.setString(" - Path");
	m_finalPath.setPosition(130, 640);
	m_finalPath.setColor(sf::Color::Black);




	resetAstar();
		
}

Game::~Game()
{
	
}

/// <summary>
/// Main game entry point - runs until user quits.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);


	while (m_window.isOpen())
	{
		//processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}

//void NodeVisited(Node * node) {
////	cout << "Visiting: " << node->data().first << endl;
//}
// <summary>
/// @brief Check for events
/// 
/// Allows window to function and exit. 
/// Events are passed on to the Game::processGameEvents() method
/// </summary>
void Game::runAstar()
{
	
	std::vector<Node *> path;

	path.clear();

	//myGraph.aStar(myGraph.nodeIndex(nodeMap[sdest[0]]), myGraph.nodeIndex(nodeMap[sdest[1]]), visit, path, passHeuristic);
	myGraph.ucs(myGraph.nodeIndex(nodeMap[sdest[0]]), myGraph.nodeIndex(nodeMap[sdest[1]]), visit, path);


	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i]->data().first << std::endl;

		std::string temp = path[i]->data().first;

		for (int i = 0; i < nodes.size(); i++)
		{
			std::string temp2 = nodes[i]->m_nameText;
			if (temp2 == temp)
			{
				nodes[i]->highlight = true;
			}

		}

	}
	
}
void Game::calculateHeuristic() {

	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->m_heuristic = 0;

		if (nodes[i]->m_nameText != startdest[1]->m_nameText)
		{
			float x = (startdest[1]->m_position.x - nodes[i]->m_position.x)*(startdest[1]->m_position.x - nodes[i]->m_position.x);
			float y = (startdest[1]->m_position.y - nodes[i]->m_position.y)*(startdest[1]->m_position.y - nodes[i]->m_position.y);

			float result = sqrt(x + y);
			nodes[i]->m_heuristic = result;

			std::cout << nodes[i]->m_heuristic << std::endl;
		}

	}
	

}

/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time time)
{
	m_mousePos = sf::Mouse::getPosition(m_window);
	for (int i = 0; i < nodes.size(); i++)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && nodes[i]->selected == false)
		{
			
			nodes[i]->mouseDetection(m_mousePos, sdest);
			if (nodes[i]->selected == true && sdest.size()<2)
			{
				sdest.push_back(nodes[i]->m_nameText);
				startdest.push_back(nodes[i]);
			}
			if (sdest.size() == 2 && active == false)
			{
				calculateHeuristic();
				active = true;
			}
			
		}

		nodes[i]->update(time);
		
	}
	for (int i = 0; i < edges.size(); i++)
	{
		edges[i]->update(time);
	}

	m_button->update(time);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_button->selected == false)
	{
		m_button->mouseDetection(m_mousePos, sdest);
		
		if (m_button->selected == true )
		{
			if (m_button->m_buttonVal == 1 && sdest.size() == 2 )
			{
				runAstar();
			}
		   else if(m_button->m_buttonVal == 0)
			{
				resetAstar();
			}

		}

	}
	else if((sf::Mouse::isButtonPressed(sf::Mouse::Left) == false))
	{
		m_button->selected = false;

	}
	
}
void Game::resetAstar()
{
	active = false;
	myGraph.clearMarks();
	sdest.clear();
	startdest.clear();
	nodes.clear();
	std::string NodeLabel;
	int posX;
	int posY;
	int i = 0;
	ifstream myfile;
	myfile.open("nodesQ2.txt");


	//m_nodeq2 = new Nodeq2(100, 100);

	while (myfile >> NodeLabel >> posX >> posY) {

		nodes.push_back(new Nodeq2(posX, posY, NodeLabel,m_font));

		nodeMap[NodeLabel] = i;
		myGraph.addNode(std::make_pair(NodeLabel, 0), i++);
	}
	//for (int i = 0; nodes.size(); i++)
	//{
		//nodes[i]->m_heuristic = 0;
	//}

	myfile.close();
	myfile.open("arcsQ2.txt");

	int from, to, weight, linefromX, linefromY, linetoX, linetoY = 0;
	std::string s_from, s_to;
	while (myfile >> s_from >> s_to >> weight >> linefromX >> linefromY >> linetoX >> linetoY) {
		from = s_from.at(0) - 'A';
		to = s_to.at(0) - 'A';
		from = nodeMap[s_from];
		to = nodeMap[s_to];
		std::cout << s_from << "," << s_to << std::endl;
		myGraph.addArc(from, to, weight);
		edges.push_back(new Edge(weight,linefromX, linefromY, linetoX, linetoY,m_font));
	}

	myfile.close();

	//system("PAUSE");

}


/// <summary>
/// @brief draw the window for the game.
/// 
/// draw buttons and text on left side
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	
	for (int i = 0; i < edges.size(); i++)
	{
		edges[i]->render(m_window);
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->render(m_window);
	}
	m_button->render(m_window);

	m_window.draw(unexpandednode);
	m_window.draw(m_unexpanded);
	m_window.draw(startdestnode);
	m_window.draw(m_startDest);
	m_window.draw(expandednode);
	m_window.draw(m_expanded);
	m_window.draw(finalpathnode);
	m_window.draw(m_finalPath);
	m_window.display();
}


