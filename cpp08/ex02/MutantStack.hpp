#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// typedef - alias with other name
		// typename - unknown type yet
		// container_type - the underlying stack that it uses , vector, list, deque?
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		// typename std::stack<T>::container_type::iterator begin();
		// typename std::stack<T>::container_type::iterator end();
		// typename std::stack<T>::container_type::const_iterator begin() const;
		// typename std::stack<T>::container_type::const_iterator end() const;
};

#include "MutantStack.tpp"

#endif