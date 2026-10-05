#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(std::string file) : _filePath(file)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : 
	_filePath(other._filePath)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_filePath = other._filePath;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

//this function doesnt cover much error since it does not specify database file need to have error handling
int	BitcoinExchange::parseRate()
{
	std::ifstream	rateFile("data.csv");
	
	if (!rateFile.is_open())
	{
		std::cerr << "Couldn't open file" << std::endl;
		return 1;
	}
	std::string line;
	std::getline(rateFile, line);
	while (std::getline(rateFile, line))
	{
		if (line.empty())
			continue ;
		size_t pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "wrong database" << std::endl;
			return 1;
		}
		std::string date = line.substr(0, pos);
		std::string excRate = line.substr(pos + 1);
		_bitcoinRate[date] = std::atof(excRate.c_str());
	}
	return 0;
}

int	BitcoinExchange::processInput()
{
	std::ifstream	quantityFile(_filePath.c_str());
	
	if (!quantityFile.is_open())
	{
		std::cerr << "Couldn't open " << _filePath << std::endl;
		return 1;
	}
	std::string line;
	std::getline(quantityFile, line);
	if (line != "date | value")
	{
		std::cerr << "Wrong first line" << std::endl;
		return 1;
	}
	std::cout << line << std::endl;
	while (std::getline(quantityFile, line))
	{
		if (line.empty())
			continue ;
		size_t pos = line.find("|");
		if (pos == std::string::npos)
		{
			std::cout << "wrong format: |" << std::endl;
			continue ;
		}
		std::string date = line.substr(0, pos);
		std::string quantity = line.substr(pos + 1);
		if (checkDate(date))
		{
			std::cout << "wrong date" << std::endl;
			continue ;
		}
		if (checkValue(quantity))
		{
			std::cout << "wrong quantity" << std::endl;
			continue ;	
		}
		getResult();
	}
	return 0;
}

int	BitcoinExchange::checkDate(std::string date)
{
	if (date.length() != 11)
		return 1;
	if (date[4] != '-' || date[7] != '-' || date[10] != ' ')
		return 1;
	std::string year	= date.substr(0, 4);
	std::string month	= date.substr(5, 2);
	std::string day		= date.substr(8, 2);

	// string of digit
	if (strdigit(year) || strdigit(month) || strdigit(day))
		return 1;
	int	yearI = atoi(year.c_str());
	int monthI = atoi(month.c_str());
	int	dayI = atoi(day.c_str());
	if (monthI < 1 || monthI > 12 || dayI < 1)
		return 1;
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	// Divisible by 4? Yes.
	// Divisible by 100? Yes. (Penalty applied: 28 days?)
	// Divisible by 400? Yes! (Bonus applied: 29 days!)
	// Result: February 2000 had 29 days.
	if (monthI == 2)
		if (yearI % 4 == 0 && (yearI % 100 != 0 || yearI % 400 == 0)) 	//leap year is a year divisible by 4 but not divisible by 100. (except divisible by 400)
			daysInMonth[2] = 29;
	if (dayI > daysInMonth[monthI])
		return 1;
	_date = date;
	return 0;
}

int	BitcoinExchange::checkValue(std::string valueStr)
{
	//			CHAR CHECK. SPACE and NON DIGIT
	if (valueStr[0] != ' ')
		return 1;
	std::string value = valueStr.substr(1);
	if (strdigit2(value))
		return 1;
	//			INVALID RANGE
	float valueF = std::atof(value.c_str());
	if (valueF < 0 || valueF > 1000)
		return 1;
	_value = valueF;
	return 0;
}

void	BitcoinExchange::getResult()
{
	std::map<std::string, float>::iterator it = _bitcoinRate.lower_bound(_date);

	// if it is the first element it should go here where iterator same as date
	if (it != _bitcoinRate.end() && it->first == _date)
		std::cout << _date << " => " << _value << " = " << (_value * it->second) <<  std::endl;
	else
	{
		// because here iterator is not same as date already so 
		// meaning it cannot find the date dy 
		// so it return first one
		if (it == _bitcoinRate.begin())
		{
			std::cerr << "Date too early: " << _date << std::endl;
			return ;
		}
		// Take the one earlier one
		it--;
		std::cout << _date << " => " << _value << " = " << (_value * it->second) <<  std::endl;
	}
}

// cannot have '.' also only pure number
int	BitcoinExchange::strdigit(std::string str)
{
	if (str.empty())
		return 1;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return 1;
	}
	return 0;
}

// allow deciman number
int	BitcoinExchange::strdigit2(std::string str)
{
	if (str.empty())
		return 1;
	size_t	i = 0;
	if (str[i] == '+')
		i++;
	if (i == str.size())
		return 1;
	int		noOfDot = 0;
	bool	hasDigit = false;
	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			noOfDot++;
			if (noOfDot > 1)
				return 1;
		}
		else if (std::isdigit(str[i]))
			hasDigit = true;
		else
			return 1;
	}
	return (!hasDigit);
}

void BitcoinExchange::printRates() const
{
    for (std::map<std::string, float>::const_iterator it = _bitcoinRate.begin(); it != _bitcoinRate.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}