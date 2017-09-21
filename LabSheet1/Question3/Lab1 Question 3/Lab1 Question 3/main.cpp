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
	int index;



	std::array<int, 3> arrayX = {};
	std::array<int, 3> arrayY = {};

	UnorderedArray<int> test(5);

	//Input elements of both arrays and push to unordered array
	std::cout << "Input X1\n";
	std::cin >> value;
	test.push(value);
	arrayX[0] = value;
	

	std::cout << "Input Y1\n";
	std::cin >> value;
	test.push(value);
	arrayY[0] = value;

	std::cout << "Input X2\n";
	std::cin >> value;
	test.push(value);
	arrayX[1] = value;

	std::cout << "Input Y2\n";
	std::cin >> value;
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

	//Call scalar product template and output result
	float scalar = scalarProduct(arrayX, arrayY);
	std::cout << "the scalar product of the two arrays are\n" << scalar << std::endl;

	std::cout << "Input a number to search for \n" << std::endl;
	std::cin >> search;

	std::cout << "This number occurs at index " << test.search(search) << "\n";

	//Display number of elements in the array before element removed 
	std::cout << "There are "<< test.getSize() <<" elements in the array" <<  std::endl;
	//Display each element in the array before 
	for (int i = 0; i < test.getSize(); i++)
	{
		std::cout << test[i] << "\n";
	}

	std::cout << "Enter index to remove " << std::endl;
	
	std::cin >> index;

	test.remove(index);

	//Display number of elements in the array before element removed 
	std::cout << "There are " << test.getSize() << " elements in the array" << std::endl;
	

	//Display each element in the array after 
	for (int i = 0; i < test.getSize(); i++)
	{
		std::cout << test[i] << "\n";
	}

	system("PAUSE");
}
