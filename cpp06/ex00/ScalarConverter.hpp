/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:05:17 by hho-jia-          #+#    #+#             */
/*   Updated: 2026/04/23 14:08:10 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define  SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip> //(1) std::fixed and std::setprecision
#include <cmath> // std::isinf and std::innan
#include <limits> //(3) std::min(), std::max(),

class ScalarConverter
{
	private:
		//(4)
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		enum e_type
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INVALID,
		};
		
		static e_type detectType(const std::string& literal);
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

	public:
		static void convert(const std::string& literal);

};

#endif