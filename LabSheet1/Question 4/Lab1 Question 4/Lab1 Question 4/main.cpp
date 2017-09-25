#include <iostream>
#include <array>
#include <vector>
#include "UnorderedArray.h"

std::vector<int> m_vectorPair;

template <typename T>
T scalarProduct(std::array<T, 3> a, std::array<T, 3> b)
{
	float scalar = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

	return scalar;

}

template <typename T>
std::pair<T, T> minMax(std::vector<T> vector)
{
	//initialise 
	int min = vector[0];
	int max = vector[0];


	//Make sure the iterator stays in range 
	for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); ++iter)
	{
		if (*iter < min)
		{
			min = *iter;
		}
		if (*iter > max)
		{
			max = *iter;
		}
	}

	return std::pair<T, T>(min, max);
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
	m_vectorPair.push_back(value);
	arrayX[0] = value;


	std::cout << "Input Y1\n";
	std::cin >> value;
	test.push(value);
	m_vectorPair.push_back(value);
	arrayY[0] = value;

	std::cout << "Input X2\n";
	std::cin >> value;
	test.push(value);
	m_vectorPair.push_back(value);
	arrayX[1] = value;

	std::cout << "Input Y2\n";
	std::cin >> value;
	test.push(value);
	m_vectorPair.push_back(value);
	arrayY[1] = value;

	std::cout << "Input X3\n";
	std::cin >> value;
	test.push(value);
	m_vectorPair.push_back(value);
	arrayX[2] = value;

	std::cout << "Input Y3\n";
	std::cin >> value;
	test.push(value);
	m_vectorPair.push_back(value);
	arrayY[2] = value;

	//Call scalar product template and output result
	float scalar = scalarProduct(arrayX, arrayY);
	std::cout << "the scalar product of the two arrays are\n" << scalar << std::endl;

	std::cout << "Input a number to search for \n" << std::endl;
	std::cin >> search;

	std::cout << "This number occurs at index " << test.search(search) << "\n";

	//Display number of elements in the array before element removed 
	std::cout << "There are " << test.getSize() << " elements in the array" << std::endl;
	//Display each element in the array before 
	for (int i = 0; i < test.getSize(); i++)
	{
		std::cout << test[i] << "\n";
	}

	std::cout << "Enter index to remove " << std::endl;

	std::cin >> index;

	test.remove(index);

	//Display number of elements in the array before element removed 
	std::cout << "There are " << test.getSize() << " elements in the array \n" << std::endl;


	//Display each element in the array after 
	for (int i = 0; i < test.getSize(); i++)
	{
		std::cout << test[i] << "\n";
	}


	//Display lowest and highest value in the vector
	std::cout << "the Min number in the vector is" << std::endl;
	std::cout << minMax(m_vectorPair).first << std::endl;
	std::cout << "the Max number in the vector is" << std::endl;
	std::cout << minMax(m_vectorPair).second << std::endl;
	
	system("PAUSE");
}