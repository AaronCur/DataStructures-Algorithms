#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include "Graph.h"
#include <utility> // for STL pair
using std::pair;

using namespace std;


typedef GraphArc<std::pair<std::string, int>,int> Arc;
typedef GraphNode<std::pair<std::string, int>, int> Node;

void NodeVisited(Node * node) {
	cout << "Visiting: " << node->data().first << endl;
}

int main(int argc, char *argv[]) {

	// Meaning of template arguments below:
	// pair<string, int> is the data we are storing at each node
	// int is the arc type (the data stored at each edge or arc)

	Graph<pair<string, int>, int > myGraph(30);
	
	//Graph<std::string, int> graph(25);


	std::string NodeLabel;
	int i = 0;
	ifstream myfile;
	myfile.open("nodes.txt");
	std::map<std::string, int>nodeMap;
	std::vector<Node *> path;

	while (myfile >> NodeLabel) {

		nodeMap[NodeLabel] = i;
		myGraph.addNode(std::make_pair(NodeLabel, 0), i++);
	}

	myfile.close();
	myfile.open("arcs.txt");

	int from, to, weight;
	std::string s_from, s_to;
	while (myfile >> s_from >> s_to >> weight) {
		//from = s_from.at(0) - 'A';
		//to = s_to.at(0) - 'A';
		from = nodeMap[s_from];
		to = nodeMap[s_to];
		std::cout << s_from << "," << s_to << std::endl;
		myGraph.addArc(from, to, weight);
	}

	myGraph.aStar(myGraph.nodeIndex(4), myGraph.nodeIndex(20), NodeVisited, path);

	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i]->data().first << std::endl;
	}

	myfile.close();

	system("PAUSE");

}