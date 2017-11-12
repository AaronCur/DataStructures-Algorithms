
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

#include "Graph.h"

using namespace std;


typedef GraphArc<std::string, int> Arc;
typedef GraphNode<std::string, int> Node;

void visit( Node * node ) {
	cout << "Visiting: " << node->data() << endl;
}

int main(int argc, char *argv[]) {

    Graph<std::string, int> graph( 25 );
	
	std::string nodeLabel;
	int i = 0;
	ifstream myfile;
	myfile.open ("nodes.txt");

	while ( myfile >> nodeLabel ) {
		graph.addNode(nodeLabel, i++);
	}

	myfile.close();
	myfile.open("arcs.txt");

	int from, to, weight;
	while ( myfile >> from >> to >> weight ) {
		graph.addArc(from, to, weight);
	}
    myfile.close();

	// Now traverse the graph.
	Node *goal = graph.nodeIndex(10);
	graph.adaptedBreadthFirst( graph.nodeIndex(0), goal, visit);
	
	//graph.adaptedBreadthFirst( graph.nodeIndex(0), graph.nodeIndex(15) );
	//Node *goal = graph.nodeIndex(15);

	//To find shortest path
	stack<Node *> path;
	auto temp = goal;
	while (temp != nullptr)
	{
		path.push(temp);
		temp = temp->previous();
	}

	while (path.size() !=0)
	{
		std::cout << "Path: " + path.top()->data() << std::endl;
		path.pop();
	}



	system("PAUSE");
	
}
