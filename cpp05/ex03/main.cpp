#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	std::cout << "\n === intern test === \n";

	std::srand(std::time(NULL));
	Bureaucrat boss("boss", 1);

	Intern someRandomIntern;
	AForm* form;

	std::cout << "\n === intern create first form === \n";
	form = someRandomIntern.makeForm("robotomy request", " bender");
	if (form)
	{
		boss.signAForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n === create another form === \n";

	form = someRandomIntern.makeForm("presidential pardon", "criminal");
	if (form)
	{
		boss.signAForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n ==== invalid form test === \n";

	form = someRandomIntern.makeForm("coffee request", "intern");
	if (form)
		delete form;

	return 0;
}