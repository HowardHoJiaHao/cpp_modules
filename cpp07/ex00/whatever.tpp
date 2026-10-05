#ifndef WHATEVER_TPP
# define WHATEVER_TPP

#include <iostream>

// When you call the function, the compiler replaces T with the actual type.
template <typename T>
void swap (T &a,T &b)
{
	std::cout << "run tmeplet " << std::endl;
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template <typename T>
T max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

#endif