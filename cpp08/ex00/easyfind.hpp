#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm> // allow the function such as find, sort, copy, count, min, max

template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
typename T::const_iterator easyfind(const T& container, int value);

#include "easyfind.tpp"

#endif