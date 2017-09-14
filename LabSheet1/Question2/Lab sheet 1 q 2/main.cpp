#include <iostream>
#include <array>
#include "UnorderedArray.h"

int main()
{
	

	UnorderedArray<int> test(5);

	test.push(4);
	test.push(2);
	test.push(3);
	test.push(7);
	test.push(8);

	std::cout<<"This number occurs at index " << test.search(6) << "\n";

	system("PAUSE");
	
}