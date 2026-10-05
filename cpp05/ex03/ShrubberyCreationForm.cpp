#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

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

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());

	file << "   ^\n";
	file << "  ^^^\n";
	file << " ^^^^^\n";
	file << "   |\n";
}