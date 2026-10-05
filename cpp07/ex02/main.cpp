#include "Array.hpp"
#include <iostream>

int main()
{
	// Default array 
	// int numbers[5] = {1, 2, 3, 4, 5};
	std::cout << " === test1: empty array ===" <<std::endl;
	Array<int> emptyArr;
	std::cout << "Size of empty array: " << emptyArr.size() << std::endl;

	std::cout << "\n === test2: parameteraized array (int) ===" <<std::endl;
	Array<int> intArr(5);
	std::cout << "size: " <<intArr.size() << std::endl;

	// verify default init (should be 0 for int)
	std::cout << "Values initialized to: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
	{
		std::cout << intArr[i] << " ";
	}
	std::cout << std::endl;

	//modifies value
	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = i * 2;

	std::cout << "Vaues after modification: ";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n === test3: out of bounds exception ===" << std::endl;
	try
	{
		std::cout << "Accessing valid index 2: " << intArr[2] << std::endl;
		std::cout << "Accessing invalid index 10 ..." << std::endl;
		intArr[10] = 42;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception caught: Index out of bounds!" << std::endl;
	}

	std::cout << "\n === test4: copy constructor(deep copy) ===" << std::endl;
	Array<int> copyArr(intArr);
	std::cout << "Original address: " <<  &intArr[0] << std::endl;
	std::cout << "copy address" << &copyArr[0] << std::endl;

	std::cout << "Modifying original " << std::endl;
	intArr[0] = 999;
	std::cout << "Original[0]: " << intArr[0] <<std::endl;
	std::cout << "Copy[0]: " << copyArr[0] << " (should not be 999)" << std::endl;
	
	std::cout << "\n === test 5: assignment operator (deep copy) ===" << std::endl;
	Array<int> assignArr;
	assignArr = intArr;
	std::cout << "origianl address: " << &intArr[0] << std::endl;
	std::cout << "Assigned address: " << &assignArr[0] << std::endl;

	std::cout << "\n === test 6: string Array === " << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "whatssup";

	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;
	
	// try {
	// 	std::cout << strArr[7] << std::endl;
	// }catch (const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;	
	// }
	
	// const Array<std::string> strArr4(3);
	// try {
	// 	std::cout << strArr4[7] << std::endl;
	// }catch (const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;	
	// }
	
	return 0;
}