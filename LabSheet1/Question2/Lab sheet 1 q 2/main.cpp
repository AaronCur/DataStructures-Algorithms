#include <iostream>
#include <array>
#include "UnorderedArray.h"

template <typename T>
T scalarProduct(std::array<T, 3> a, std::array<T, 3> b)
{
	float scalar = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

	return scalar;

}

int main()
{
	
	int search;
	int value;
	


	std::array<int, 3> arrayX = {};
	std::array<int, 3> arrayY = {};

	UnorderedArray<int> test(5);

	std::cout << "Input X1\n";
	std::cin >> value;
	test.push(value);
	arrayX[0] = value;
	//test.push(arrayX[0]);

	std::cout << "Input Y1\n";
	std::cin >> value;
	test.push(value);
	arrayY[0] = value;

	std::cout << "Input X2\n";
	std::cin >> value;
	test.push(value);
	arrayX[1] = value;

	std::cout << "Input Y2\n";
	std::cin >> arrayY[1];
	test.push(value);
	arrayY[1] = value;

	std::cout << "Input X3\n";
	std::cin >> value;
	test.push(value);
	arrayX[2] = value;

	std::cout << "Input Y3\n";
	std::cin >> value;
	test.push(value);
	arrayY[2] = value;


	/*test.push(arrayX[0]);
	test.push(arrayY[0]);
	test.push(arrayX[1]);
	test.push(arrayY[1]);
	test.push(arrayX[2]);
	test.push(arrayY[2]);*/


	float scalar = scalarProduct(arrayX, arrayY);
	std::cout << "the scalar product of the two arrays are\n" << scalar << std::endl;
	
	std::cout << "Input a number to search for \n" << std::endl;
	std::cin >> search;

	std::cout << "This number occurs at index " << test.search(search) << "\n";
	

	system("PAUSE");
	
}