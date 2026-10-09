#include "iter.hpp"
//#include <iostream>

void increment(int& value)
{
	value++;
}

void printChar(const char& c)
{
	std::cout << c << " ";
}

void printString(const std::string& s)
{
	std::cout << s << " ";
}

int main()
{
	int number[] = {1, 2, 3, 4, 5};
	const int constNumbers[] = {10, 20, 30};

	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charLen = sizeof(charArr) / sizeof(charArr[0]);

	std::string strArray[] = {"hello", "world", "templates"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << " === to test multiple type of array, char array and string" << std::endl;

	std::cout << "\noriginal char array: ";
	iter(charArr, charLen, printChar);
	std::cout << std::endl;

	std::cout << "\n test modified char array: ";
	iter(charArr, strLen, charToUpper<char>);
	std::cout << std::endl;

	std::cout << "\nOriginal string array: ";
	iter(strArray, strLen, printString);
	std::cout << std::endl;

	std::cout << "\n test modified str array: ";
	iter(strArray, strLen, strToUpper<std::string>);
	std::cout << std::endl;

	std::cout << "original number: ";
	iter(number, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "incremented number: ";
	iter(number, 5, increment);
	iter(number, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "const numbers: ";
	iter(constNumbers, 3, printElement<int>);
	std::cout << std::endl;

	return 0;
}
