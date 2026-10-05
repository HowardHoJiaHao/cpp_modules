#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	protected:
		void executeAction() const;

	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
};

#endif