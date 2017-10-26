#include <iostream>
#include "SLinkedList.h"

using namespace std;

int main() {

	// Part 1: Demonstrate the very basic prinicpals of a linked list.

	// Create a list node (there is no list object).
	//std::unique_ptr<SListNode<int>> p1 = std::make_unique<SListNode<int>>(3);
	//// Create a second list node, and link the first node to the second.
	//p1->setNext(std::make_unique<SListNode<int>>(4));
	//// Loop through each node in the list.
	//for (SListNode<int> *pCurrent = p1.get(); pCurrent != nullptr; pCurrent = pCurrent->next().get())
	//{
	//	cout << (*pCurrent).element() << endl;
	//}
	// Q: What happens if the next line is uncommented?
	//p1 = std::move(p1->next());

	// Part 2: Create a linked list using a list object.


	


	//
	//auto next = list.begin();
	//next++;
	//std::swap(*list.begin(), *next);
	//

	//SListIterator<int> start = list.begin();
	//
	//cout << "First element: " << *start << endl;

	//cout << list.size() << endl;

	//std::list<int> source, target;
	//source.push_back(10);
	//source.push_back(20);
	//source.push_back(30);
	//target.push_back(40);
	//target.push_back(50);

	//source.splice(source.end(), target );

	//auto rbegin = source.rbegin();
	//auto rend = source.rend();
	//for (; rbegin != rend; rbegin++)
	//{
	//	std::cout << *rbegin << std::endl;
	//}

	// Lab2 Q1
	cout << "Lab2 Q1" << endl;
	SLinkedList<int, SListIterator<int>> list;
	//std::list<int> & x = std::list<int>();
	list.insertFirst(10);
	list.insertFirst(20);
	list.insertFirst(30);
	list.insertFirst(40);
	list.insertFirst(60);
	
	SListIterator<int> iter = list.begin();
	iter++;
	
	list.insertBefore(iter, 50);

	SListIterator<int> current = list.begin();
	SListIterator<int> last = list.end();

	for (; current != last; ++current)
	{
		cout << *current << endl;
	}

	cout << "size: " << list.size() << endl;
	cout << "isEmpty: " << list.isEmpty() << endl;

	//Lab2 q2
	cout << "Lab2 Q2 Reverse" << endl;
	list.reverse();
	current = list.begin();
	last = list.end();
	for (; current != last; ++current)
	{
		cout << *current << endl;
	}

	// Lab2 q3
	cout << "Lab2 Q3 splice" << endl;
	std::list<int> & x = std::list<int>();
	x.push_back(2);
	x.push_back(4);
	x.push_back(6);
	x.push_back(8);
	list.splice(list.begin(), x);

	current = list.begin();
	last = list.end();
	for (; current != last; ++current)
	{
		cout << *current << endl;
	}

	cout << "size: " << list.size() << endl;
	system("PAUSE");
}
