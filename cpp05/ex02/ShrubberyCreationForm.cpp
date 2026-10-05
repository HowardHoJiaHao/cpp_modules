#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
	// std::cout << "A Shrubbery was planted" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// If the file does not exist, it will be created.
// If it already exists, its contents are usually overwritten.
// The file gets closed automatically when file goes out of scope.

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());

	file << "   ^\n";
	file << "  ^^^\n";
	file << " ^^^^^\n";
	file << "   |\n";
}