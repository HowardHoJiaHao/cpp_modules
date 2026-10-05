/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:05:24 by hho-jia-          #+#    #+#             */
/*   Updated: 2026/04/23 15:31:52 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(const std::string& literal)
{
	
	if (literal.length() == 1 && std::isprint(literal[0]))
		return (literal.length() == 1 && std::isprint(literal[0]));
	return (literal.length() ==  3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	if (i == literal.length()) //if nothing after sign
		return false;
	for (; i < literal.length() ; i++)
	{
		if (!isdigit(literal[i])) // ensure digit character after optional sign
			return false;
	}
	return true;
}

// at least one digit
// exactly one dot
// ending f suffix

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.empty())
		return false;

	bool hasDecimal			= false;
	bool hasDigits			= false;
	size_t len;
	std::string numPart;
	size_t i				= 0;

	if (literal == "-inff" || literal == "+inff" 
		|| literal == "nanf" || literal == "inff")
		return true;
	len = literal.length();
	
	// 0.f -> valid
	// .0f -> valid
	if (len < 2 || literal[len - 1] != 'f') //leng < 2 or last is not f
		return false;
	numPart = literal.substr(0, len - 1); // remove f
	i = 0;
	if (numPart[0] == '-' || numPart[0] == '+')
		i++;
	for (; i < numPart.length(); i++)
	{
		if (numPart[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (isdigit(numPart[i]))
		{
			hasDigits = true;
		}
		else
			return false;
	}
	return hasDigits && hasDecimal;
}

// "0" -> false (has digit, but no dot)
// "0." -> true (has digit + dot)
// ".0" -> true (has digit + dot)

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;

	bool hasDecimal		= false;
	size_t i			= 0;
	bool hasDigits		= false;

	if (literal == "-inf" || literal == "+inf"
		|| literal == "nan" || literal == "inf")
			return true;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDecimal)
				return false;
			hasDecimal = true;
		}
		else if (isdigit(literal[i]))
			hasDigits = true;
		else
			return false;
	}
	return hasDigits && hasDecimal;
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& literal)
{
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return INVALID;
}

void ScalarConverter::printChar(double value)
{
	char c;

	std::cout << "char: ";
	// std::isnan(value) means value is NaN (Not-a-Number)
	// std::isinf(value) means value is infinity (+inf or -inf)
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	// std::numeric_limits<char>::min() gives the smallest value a char can hold.
	// std::numeric_limits<char>::max() gives the largest value a char can hold.
	if (value < std::numeric_limits<char>::min() 
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "impossible (oveflow / underflow)" << std::endl;
		return;
	}
	c = static_cast<char>(value);
	if (std::isprint(c))
		std::cout << "'" << c << "'" <<std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value)
{
	std::cout << "int: ";

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std::endl;
		return;
	}
	// std::numeric_limits<int>::min() = smallest int allowed (usually -2147483648)
	// std::numeric_limits<int>::max() = largest int allowed (usually 2147483647)
	if (value < std::numeric_limits<int>::min() 
		|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible (overflow / underflow)" << std::endl;
		return; 
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
	std::cout << "float: ";

	// change to float
	float f = static_cast<float>(value);
	
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;

	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
	
	else
	{
		// scientific notation
		// 4.226e+01
		// 1.0e+03
		// 3.5e-02
		// std::fixed force the float from scientific notation into normal decimal form 
		// std::setprecision(1) shows exactly 1 digit after the decimal point
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		// std::cout << std::setprecision(1) << f << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";

	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	e_type type		= detectType(literal);
	double value	= 0.0;
	std::string tmp;
	long long ll;

	switch (type)
	{
		case CHAR:
		{
			std::cout <<" This i "<< literal[0] << std::endl;
			if (literal.length() == 3)
				value = static_cast<double>(literal[1]);
			else 
				value = static_cast<double>(literal[0]);
			break;
		}
		case INT:
		{
			ll = atoll(literal.c_str());
			value = static_cast<double>(ll);
			break;
		}
		case FLOAT: //(1)
		{
			if (literal == "-inff")
				value = -std::numeric_limits<double>::infinity(); //output : -inf
			else if (literal == "+inff" || literal == "inff")
				value = std::numeric_limits<double>::infinity(); //output : inf
			else if (literal == "nanf")
				value = std::numeric_limits<double>::quiet_NaN(); //output : NaN
			else
			{
				tmp = literal.substr(0, literal.length() - 1);
				value = strtod(tmp.c_str(), NULL); // converts to double, second argument save where the convert stop
			}
			break;
		}
		case DOUBLE:
		{
			if (literal == "-inf")
				value = -std::numeric_limits<double>::infinity();
			else if (literal == "+inf" || literal == "inf")
				value = std::numeric_limits<double>::infinity();
			else if (literal == "nan")
				value = std::numeric_limits<double>::quiet_NaN();
			else
				value = strtod(literal.c_str(), NULL);
			break;
		}
		case INVALID:
		default:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}