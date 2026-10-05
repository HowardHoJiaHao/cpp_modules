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
		typedef typename std::stack<T>::container_type::iterator iter;
		typedef typename std::stack<T>::container_type::const_iterator const_iter;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		iter begin();
		iter end();
		const_iter begin() const;
		const_iter end() const;

		// typename std::stack<T>::container_type::iterator begin();
		// typename std::stack<T>::container_type::iterator end();
		// typename std::stack<T>::container_type::const_iterator begin() const;
		// typename std::stack<T>::container_type::const_iterator end() const;
};

#include "MutantStack.tpp"

#endif