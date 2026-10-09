#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <cctype>

template <typename T, typename F>
void iter(T* array, const size_t length, F func)
{
	if (!array || !func)
		return;
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void printElement(const T& value)
{
	std::cout << value << " ";
}

template <typename T>
void charToUpper(const T& character)
{
	// std::toupper expects an int argument that must be either EOF or representable as an unsigned char. Passing a plain char (which may be signed and negative) can cause undefined behavior for non-ASCII values.
	// static_cast<unsigned char>(character) ensures the value is in the valid range for std::toupper.
	// std::toupper returns an int, which is either EOF or the converted character as an unsigned char value. To get a char result, you cast it back with static_cast<char>.
	char tempChar = static_cast<char>(std::toupper(static_cast<unsigned char>(character)));
	std::cout << tempChar << " ";
}

template <typename T>
void strToUpper(const T& str)
{
	//std::cout << "|" <<  str << "|" << std::endl;
	for (long unsigned int i = 0; i < str.length(); i++)
		std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	std::cout << " ";
}

#endif
