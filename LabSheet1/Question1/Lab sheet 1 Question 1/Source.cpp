#include <iostream>
#include <array>

template <typename T>
T scalarProduct(std::array<T, 3> a, std::array<T, 3> b)
{
	float scalar = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

	return scalar;
	
}

int main()
{
	std::array<int, 3> arrayX = { };
	std::array<int, 3> arrayY = { };
	std::cout << "Input X1\n";
	std::cin >> arrayX[0];
	std::cout << "Input Y1\n";
	std::cin >> arrayY[0];
	std::cout << "Input X2\n";
	std::cin >> arrayX[1];
	std::cout << "Input Y2\n";
	std::cin >> arrayY[1];
	std::cout << "Input X3\n";
	std::cin >> arrayX[2];
	std::cout << "Input Y3\n";
	std::cin >> arrayY[2];

	
	
	float scalar = scalarProduct(arrayX, arrayY);
	std::cout << "the scalar product of the two arrays are\n";
	std::cout << scalar;
	system("PAUSE");


}
