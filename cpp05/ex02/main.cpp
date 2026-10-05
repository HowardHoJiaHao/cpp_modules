#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	std::srand(std::time(NULL));


	std::cout << "\n ==== create bureaucrats === \n";
	Bureaucrat boss("boss", 1);
	Bureaucrat mid("mid", 50);
	Bureaucrat intern("intern", 150);

	std::cout << "\n==== create Forms ==== \n";
	ShrubberyCreationForm tree("garden");
	RobotomyRequestForm robot("marvin");
	PresidentialPardonForm pardon("criminal");

	std::cout << "\n === Test 1: execute unsigned form === \n";
	boss.executeForm(tree);

	std::cout << "\n === test2 : sign with low grade ==== \n";
	intern.signAForm(pardon);

	std::cout << "\n ==== test3 : proper signing ==== \n";

	//treat derived object as base
	boss.signAForm(tree);
	boss.signAForm(robot);
	boss.signAForm(pardon);
	

	std::cout << "\n ==== test4: execution with low grade ==== \n";
	intern.executeForm(tree);
	
	std::cout << "\n ===== test5 : successful execution === \n";
	boss.executeForm(tree);
	boss.executeForm(pardon);

	std::cout << "\n === test6 : robotomy randomness === \n";
	for (int i = 0; i < 5; i++)
		boss.executeForm(robot);

	std::cout << "\n ==== test7 : polymorphism === \n";
	AForm* poly = new ShrubberyCreationForm("poly_tree");

	boss.signAForm(*poly);
	boss.executeForm(*poly);

	delete poly;

}