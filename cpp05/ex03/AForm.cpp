#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), 
	_gradeToExecute(150)
{
	std::cout << "Aform default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), 
	_gradeToExecute(gradeToExecute)
{
	std::cout << "AForm parameteriazed constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignemnt operator called" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AFOrm destructor called" << std::endl;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high! (must be >= 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low! (must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form: " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	<< ", grade to sign: " << form.getGradeToSign() << ", grade to execute: "
	<< form.getGradeToExecute();
	
	return os;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();

	executeAction();
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}