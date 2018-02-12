#include "LinkedBinaryTree.h"
#include "BinaryTreeIterator.h"

#include <iostream>

template<typename T>
void postOrder(BinaryTreeNode<T>* node)
{
	if (node->leftChild().node() != nullptr)
	{
		postOrder(node->leftChild().node());
	}

	if (node->rightChild().node() != nullptr)
	{
		postOrder(node->rightChild().node());
	}

	std::cout << node->element() << std::endl;

}

template<typename T, typename Iterator>
void binaryPreorder(Iterator position)
{
	std::cout << "Visiting" << (*position).element() << std::endl;
	if (position != 0)
	{
		
		if ((*position).leftChild().node() != nullptr)
		{
			binaryPreorder<BinaryTreeIterator<float>>((*position).leftChild().node());
		}

		if ((*position).rightChild().node() != nullptr)
		{
			binaryPreorder<BinaryTreeIterator<float>>((*position).rightChild().node());
		}
	}
		

}

template<typename T>
void inOrder(BinaryTreeNode<T>* node)
{
	if (node->leftChild().node() != nullptr)
	{
		postOrder(node->leftChild().node());
	}

	if (node->rightChild().node() != nullptr)
	{
		postOrder(node->rightChild().node());
	}

	std::cout << node->element() << std::endl;

}

int main() {	

	LinkedBinaryTree<int, BinaryTreeIterator<int>> myTree(10);

	myTree.insertItem(5, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(15, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(25, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(35, myTree.root(), myTree.parent(myTree.root()) );
    
	//Lab 6: Uncomment below to test your solution to depth()...
	BinaryTreeIterator<int> iter = myTree.root();
	
	//iter.downRight();
	//iter.downRight();
	//iter.downRight();
	
	auto minimumVal = myTree.treeMinimum(iter);

	
	std::cout << "Depth of node: " << *iter << " is " << myTree.depth( iter ) << std::endl;

	//std::cout << "Depth of node: " << *iter << " is " << myTree.depthNonRecursive( iter ) << std::endl;

	std::cout << "Minimum Value: " << *minimumVal<< std::endl;
	binaryPreorder<BinaryTreeIterator<float>>(myTree.root().node());
   // postOrder(myTree.root().node());
	//binaryPreorder(myTree.root());

	system("PAUSE");
	
}


