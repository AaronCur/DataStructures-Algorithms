#include "SFML/Audio.hpp"
#include "Game.h"
Graph<pair<string, int>, int > myGraph(30);

Graph<std::string, int> graph(25);

static double const MS_PER_UPDATE = 10.0;

using std::pair;

using namespace std;

std::vector<Nodeq2 *> nodes;




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
Game::Game() :
	m_window(sf::VideoMode(1280, 720, 32), "AstarProject")
{
	if (!m_agentOrange.loadFromFile("./resources/images/AGENTORANGE.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	if (!m_meatLoaf.loadFromFile("./resources/images/Meatloaf.ttf"))
	{
		std::cout << "problem loading font" << std::endl;
	}
	if (!m_adventure.loadFromFile("c:/windows/fonts/Adventure.otf"))
	{
		std::cout << "problem loading font" << std::endl;
	}


	// Meaning of template arguments below:
	// pair<string, int> is the data we are storing at each node
	// int is the arc type (the data stored at each edge or arc)


	std::string NodeLabel;
	int posX;
	int posY;
	int i = 0;
	ifstream myfile;
	myfile.open("nodesQ2.txt");
	

	//m_nodeq2 = new Nodeq2(100, 100);
	m_edge = new Edge(100, 100,100,100);

	while (myfile >> NodeLabel >> posX >> posY) {

		nodes.push_back(new Nodeq2(posX, posY,NodeLabel));

		nodeMap[NodeLabel] = i;
		myGraph.addNode(std::make_pair(NodeLabel, 0), i++);
	}

	myfile.close();
	myfile.open("arcsQ2.txt");

	int from, to, weight, linefromX, linefromY, linetoX, linetoY;
	std::string s_from, s_to;
	while (myfile >> s_from >> s_to >> weight >> linefromX >> linefromY >> linetoX >> linetoY) {
		from = s_from.at(0) - 'A';
		to = s_to.at(0) - 'A';
		from = nodeMap[s_from];
		to = nodeMap[s_to];
		std::cout << s_from << "," << s_to << std::endl;
		myGraph.addArc(from, to, weight);
		edges.push_back(new Edge(linefromX, linefromY, linetoX, linetoY));
	}

	myfile.close();

	//system("PAUSE");
		
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

	myGraph.aStar(myGraph.nodeIndex(nodeMap[sdest[0]]), myGraph.nodeIndex(nodeMap[sdest[1]]), visit, path);

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


/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time time)
{
	if (sdest.size() == 2 && active == true)
	{
		runAstar();
		active = false;
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && nodes[i]->selected == false)
		{
			m_mousePos = sf::Mouse::getPosition(m_window);
			nodes[i]->mouseDetection(m_mousePos, sdest);
			if (nodes[i]->selected == true)
			{
				sdest.push_back(nodes[i]->m_nameText);
			}
			
		}

		nodes[i]->update(time);
		
	}
	for (int i = 0; i < edges.size(); i++)
	{
		edges[i]->update(time);
	}
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
	m_window.display();
}


