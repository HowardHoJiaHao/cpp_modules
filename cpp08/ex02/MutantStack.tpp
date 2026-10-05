#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other){}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
typename MutantStack<T>::iter MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iter MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iter MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iter MutantStack<T>::end() const
{
	return (this->c.end());
}

// template <typename T>
// typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
//     return this->c.begin();
// }

// template <typename T>
// typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
//     return this->c.end();
// }

// template <typename T>
// typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const {
//     return this->c.begin();
// }

// template <typename T>
// typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const {
//     return this->c.end();
// }

#endif