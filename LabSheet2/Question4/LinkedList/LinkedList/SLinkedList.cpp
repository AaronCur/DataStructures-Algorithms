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

	std::list<int> source, target;
	source.push_back(10);
	source.push_back(20);
	source.push_back(30);
	target.push_back(40);
	target.push_back(50);

	source.splice(source.end(), target );

	auto rbegin = source.rbegin();
	auto rend = source.rend();
	for (; rbegin != rend; rbegin++)
	{
		std::cout << *rbegin << std::endl;
	}


	// Lab2 Q3
	SLinkedList<int, SListIterator<int>> list;
	std::list<int> & x = std::list<int>();
	list.insertLast(20);
	list.insertLast(10);
	x.push_back(5);
	x.push_back(55);
	list.splice(list.begin(), x);

	std::cout << list.size() << std::endl;
	// Lab2 Q4
	std::list<int> randList, dest;
	

	//Get 20 random numbers between 1 and 10 and push them 
	for (int i = 0; i < 20; i++)
	{
		randList.push_back(rand() % 10 + 1);
	}
	auto begin = randList.begin();
	auto end = randList.end();
	for (; begin != end; begin++)
	{
		std::cout << *begin << std::endl;
	}

	cout << "\n" << endl;

	std::list <int> ::iterator start;
	start = dest.begin();
	std::list <int> ::reverse_iterator find2;
	find2 = std::find(randList.rbegin(), randList.rend(), 2);

	std::list <int> ::iterator find4;
	find4 = std::find(randList.begin(), randList.end(), 4);

	
	
	dest.splice(start, randList, find2.base(),find4);
	begin = dest.begin();
	end = dest.end();
	for (; begin != end; begin++)
	{
		std::cout << *begin << std::endl;
	}
	

	system("PAUSE");
}
