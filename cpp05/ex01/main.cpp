#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== test1 : form construction === " << std::endl;
	try
	{
		Form  f1("tax return", 50, 25);
		std::cout << f1 << std::endl;

		Form f2("Permission slip", 100, 100);
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === test2: form grade too high === " <<std::endl;
	try
	{
		Form f("Invalid", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() <<std::endl;
	}

	std::cout << "\n === Test3 : form grade too low === " <<std::endl;
	try
	{
		Form f("invalid", 50, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception caught: " <<  e.what() << std::endl;
	}
	
	std::cout << "\n === test4 : successful signing === " << std::endl;
	try
	{
		Bureaucrat bob("bob", 40);
		
		Form tax("tax form", 50, 30);

		std::cout << "before: " << tax <<std::endl;
		std::cout <<  " #DEBUG: the grade is " <<bob.getGrade() << " and <= the grade to sign: ";
		std::cout <<  tax.getGradeToSign() << std::endl;
		bob.signForm(tax);
		std::cout << "after: " << tax << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	
	std::cout << "\n === test5 :failed signing( grade too low) == " <<std::endl;
	try
	{
		Bureaucrat jim("jim" , 100);
		Form secret("secret document", 50, 20);

		std::cout << "Before: " << secret << std::endl;
		jim.signForm(secret);
		std::cout << " DEBUG: " << jim.getGrade() << " is >= " << secret.getGradeToSign() << " grade to sign" << std::endl;
		std::cout << "after: " << secret <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "unexpected exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n === test6 : besigned directly throws exception === " <<std::endl;
	try
	{
		Bureaucrat newbie("newbie",  150);
		Form important("important", 1, 1);
		std::cout << " DEBUG: " << newbie.getGrade() << " is >= " << important.getGradeToSign() << " grade to sign" << std::endl;
		important.beSigned(newbie);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	

	std::cout << " \n === test7: form copy and assignemnt === " << std::endl;

	try
	{
		Form original("original" , 50, 40);
		original.beSigned(Bureaucrat("temp", 30));

		Form copy(original);
		std::cout << "Origianl: "<< original << std::endl;
		std::cout << "copy: " << copy << std::endl;

		Form assigned("assigned", 100, 100);
		assigned = original;
		std::cout << "Assigned: " << assigned << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " exception" << e.what() << std::endl;
	}
	
	
}