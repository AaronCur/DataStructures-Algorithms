
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;


#include <utility> // for STL pair
using std::pair;
int main() {

	// Meaning of template arguments below:
	// pair<string, int> is the data we are storing at each node
	// int is the arc type (the data stored at each edge or arc)

	Graph< pair<string, int>, int > myGraph(6);
	system("PAUSE");
	
}
