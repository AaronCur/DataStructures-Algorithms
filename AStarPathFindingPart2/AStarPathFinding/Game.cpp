#include "SFML/Audio.hpp"
#include "Game.h"

static double const MS_PER_UPDATE = 10.0;

using std::pair;

using namespace std;


typedef GraphArc<std::pair<std::string, int>, int> Arc;
typedef GraphNode<std::pair<std::string, int>, int> Node;


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

	Graph<pair<string, int>, int > myGraph(30);

    Graph<std::string, int> graph(25);


	std::string NodeLabel;
	int posX;
	int posY;
	int i = 0;
	ifstream myfile;
	myfile.open("nodesQ2.txt");
	std::vector<Node *> path;
	

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

	myGraph.aStar(myGraph.nodeIndex(4), myGraph.nodeIndex(20), NodeVisited, path);

	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i]->data().first << std::endl;
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
		processEvents();
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
void Game::processEvents()
{
//	sf::Event event;
//	while (m_window.pollEvent(event))
	//{
		//if (event.type == sf::Event::Closed)
		//{
			//m_window.close();
		//}
//		event.type == sf::Event::KeyPressed;
		//To check for the Akeypress to transition from splash screen to main menu
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		//{
			//m_splashScreen->checkButtonPress();
		//}
	///	if (m_mainMenu->close)
		//{
		//	m_window.close();
	//	}
		///sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
	//}

}


/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time time)
{
	for (int i = 0; i < nodes.size(); i++)
	{
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


