#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Graph.h"
#include <utility> // for STL pair
using std::pair;

using namespace std;


typedef GraphArc<std::string, int> Arc;
typedef GraphNode<std::string, int> Node;

void visit(Node * node) {
	cout << "Visiting: " << node->data() << endl;
}

int main(int argc, char *argv[]) {

	// Meaning of template arguments below:
	// pair<string, int> is the data we are storing at each node
	// int is the arc type (the data stored at each edge or arc)

	Graph< pair<string, int>, int > graph(6);

	//Graph<std::string, int> graph(25);


	std::string nodeLabel;
	int i = 0;
	ifstream myfile;
	myfile.open("nodesQ2.txt");

	while (myfile >> nodeLabel) {
		graph.addNode(std::make_pair(nodeLabel, i), i++);
	}

	myfile.close();
	myfile.open("arcsQ2.txt");

	int from, to, weight;
	while (myfile >> from >> to >> weight) {
		graph.addArc(from, to, weight);
	}
	myfile.close();

	// Now traverse the graph.
	//graph.depthFirst(graph.nodeIndex(0), visit);
	//graph.breadthFirst(graph.nodeIndex(0), visit);
	//graph.adaptedBreadthFirst( graph.nodeIndex(0), graph.nodeIndex(15) );
	//Node *goal = graph.nodeIndex(15);

	system("PAUSE");

}