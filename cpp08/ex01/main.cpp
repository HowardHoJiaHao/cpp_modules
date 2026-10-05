#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

void printTestHeader(const std::string& testName)
{
	std::cout << "\n === " << testName << " === " << std::endl;
}

void testBasicFunctionality()
{
	printTestHeader("test 1: basic functionality");
	
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptions()
{
	printTestHeader("test 2: exception handling");

	try
	{
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "Added 3 numbers successfully" << std::endl;

		sp.addNumber(4);
		std::cout << "Error: should throw exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	try
	{
		Span sp = Span(1);
		sp.addNumber(42);
		sp.shortestSpan();
		std::cout << "error: should have throw exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught expeced exception: " << e.what() << std::endl;
	}

	try
	{
		Span sp = Span(10);
		sp.longestSpan();
		std::cout << "error: should have throw exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void testLargeSpan()
{
	printTestHeader("test3 : large span (10k numbers)");
	Span sp = Span(10000);
	std::srand(std::time(NULL));

	for (int i = 0; i < 10000; ++i)
	{
		sp.addNumber(std::rand());
	}
	std::cout << "added 10k random numbers" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testAddNumbers()
{
	printTestHeader("test 4: addNumbers range");
	int values[] = {42, 7, 100, 90, 44};
	Span sp = Span(5);
	sp.addNumbers(values, values + 5);

	std::cout << "Added range of 5 numbers" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	try
	{
		int extra[] = {1};
		sp.addNumbers(extra, extra + 1);
		std::cout << "Error: should throw exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "caught expected exception: " << e.what() << std::endl;
	}
}

void testProgressiveAddNumbers()
{
	printTestHeader("test 5: progressive addNumbers");
	Span sp = Span(10);

	int initial[] = {1, 3, 5};
	sp.addNumbers(initial, initial + 3);
	std::cout << "After initial add, size: " << sp.size() << std::endl;
	sp.printVector(sp.getNumbers());

	int more[] = {7, 9, 11};
	sp.addNumbers(more, more + 3);
	std::cout << "After second add, size: " << sp.size() << std::endl;
	sp.printVector(sp.getNumbers());

	int moretwo[] = {27, 19, 1};
	sp.addNumbers(moretwo, moretwo + 3);
	std::cout << "After second add, size: " << sp.size() << std::endl;
	sp.printVector(sp.getNumbers());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main()
{
	try
	{
		testBasicFunctionality();
		testExceptions();
		testLargeSpan();
		testAddNumbers();
		testProgressiveAddNumbers();
	}
	catch (const std::exception& e)
	{
		std::cerr << " Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}