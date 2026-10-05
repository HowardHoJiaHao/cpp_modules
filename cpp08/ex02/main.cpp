
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== test ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iter it = mstack.begin();
	MutantStack<int>::iter ite = mstack.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n === comparison with std::list ===" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout <<lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();

	++it2;
	--it2;
	
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << "\n === additional test === " << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("hello");
	strStack.push("world");
	strStack.push("!");

	std::cout << "string stack contents: " << std::endl;
	for (MutantStack<std::string>::iter i = strStack.begin(); i != strStack.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	return 0;
}
