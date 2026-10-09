#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);

		std::vector<int>::iterator iter = easyfind(vec, 20);
		std::cout << "Found it vector: " << *iter << std::endl;

		const std::vector<int>& cvec = vec;
		std::vector<int>::const_iterator citer = easyfind(cvec, 30);
		std::cout << "Found in const vector: " << *citer << std::endl;

		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(15);
		lst.push_back(25);

		std::list<int>::iterator iter2 = easyfind(lst, 15);
		std::cout << "Found in list: " << *iter2 << std::endl;

		std::deque<int> deq;
		deq.push_back(1);
		deq.push_back(2);
		deq.push_back(3);

		std::deque<int>::iterator iter3 = easyfind(deq, 42);
		std::cout << "Found in deque: " << *iter3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
}