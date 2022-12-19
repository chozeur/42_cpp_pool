#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 42
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (size_t i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		for (size_t i = 0; i < tmp.size(); ++i)
			std::cout << "tmp[" << i << "] = " << tmp[i] << std::endl;
		std::cout << std::endl << std::endl;
		Array<int> test(tmp);
		for (size_t i = 0; i < test.size(); ++i)
			std::cout << "test[" << i << "] = " << test[i] << std::endl;
		std::cout << std::endl << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;	// must throw an exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;	// must throw an exception
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}
