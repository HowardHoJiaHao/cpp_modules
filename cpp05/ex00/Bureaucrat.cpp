#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	//std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	//std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	// what if empty name
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :_name(other._name), _grade(other._grade) 
{
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	//std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();	
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

// what() virtual function from std::exception
// its job is to return a human-readable error message (string)

// const - functino does not modify the exception object

// throw() - this function promises not to throw any exception
// modern is noexcept

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high ! (must be >= 1)"; 
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! (must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}