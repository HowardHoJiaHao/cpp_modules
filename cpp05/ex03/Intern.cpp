#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) { return *this;}

Intern::~Intern() {}

// static 
// Only code inside Intern.cpp can call createShrubbery, createRobotomy, and createPresidential.
// Other .cpp files cannot use those functions, even if they include Intern.hpp.
// The linker will not treat them as global symbols, so you avoid name conflicts with functions of the same name in other files.

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string names[3] = 
	{
		"shrubbery creation",
		"robotomy request" ,
		"presidential pardon"
	};

	AForm* (*creators[3])(const std::string&) =
	{
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	std::cout << " Intern cannot create \"" << formName << "\"" << std::endl;
	return NULL;
}