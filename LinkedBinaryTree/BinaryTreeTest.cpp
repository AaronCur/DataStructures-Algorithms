#include "LinkedBinaryTree.h"
#include "BinaryTreeIterator.h"

#include <iostream>


int main() {	

	LinkedBinaryTree<int, BinaryTreeIterator<int>> myTree(10);

	myTree.insertItem(5, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(15, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(25, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(35, myTree.root(), myTree.parent(myTree.root()) );
    
	 //Lab 6: Uncomment below to test your solution to depth()...
	BinaryTreeIterator<int> iter = myTree.root();
	
	iter.downRight();
	iter.downRight();
	iter.downRight();
	
	std::cout << "Depth of node: " << *iter << " is " << myTree.depthNonRecursive( iter ) << std::endl;
	

	system("PAUSE");
	
}

