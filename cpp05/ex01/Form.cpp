#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), 
	_gradeToExecute(150)
{
	//std::cout << "form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), 
	_gradeToExecute(gradeToExecute)
{
	//std::cout << "Form parameteriazed constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	//std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	//std::cout << "Form copy assignemnt operator called" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form()
{
	//std::cout << "FOrm destructor called" << std::endl;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high! (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low! (must be <= 150)";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	<< ", grade to sign: " << form.getGradeToSign() << ", grade to execute: "
	<< form.getGradeToExecute();
	
	return os;
}