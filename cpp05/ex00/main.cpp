#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== test1 : successful case === " << std::endl;
	try 
	{
		Bureaucrat b1("Alice" , 1);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;

		Bureaucrat b3("charlie", 75);
		std::cout << b3 << std::endl;

	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== test2: Grade too high on construction ===" << std::endl;
	
	try
	{

		Bureaucrat c("test 1", 50);
		std::cout << c << std::endl;

		std::cout << "special test" <<std ::endl;
		//here already error so wont run the below code stright go exception
		Bureaucrat b("Too high", 0); 

		std::cout << "you might NOT see this LINE" << std::endl;

		Bureaucrat d("test 2", 100);
		std::cout << d << std::endl;
	} 
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n === Test3 : Grade too low on construction === " << std::endl;

	try
	{
		Bureaucrat b("too low", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n === Test4 : increament or Decrement === " <<std::endl;
	try
	{
		Bureaucrat b ("test", 3);
		std::cout << "initial: " << b << std::endl;

		b.incrementGrade();
		std::cout << "after increment: " << b << std::endl;

		b.incrementGrade();
		std::cout << "after increment: " << b << std::endl;

		b.incrementGrade();
		std::cout << "after increment: " << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() <<std::endl;
	}
	
	std::cout << "\n === test5: decrement too low === " << std::endl;
	try
	{
		Bureaucrat b("low rank", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n === test6: copy constructor and assignemtn ===" << std::endl;

	try
	{
		Bureaucrat b1("Origianl", 42);
		Bureaucrat b2(b1);
		std::cout << " Original: " << b1 << std::endl;
		std::cout << " copy: " << b2 << std::endl;

		Bureaucrat b3("other", 100);
		b3 = b2;
		std::cout << "after assignement: " << b3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	return 0;
}