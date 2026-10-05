template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("value not found");
	return iter;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end)
	// You would use std::runtime_error for things that aren't the programmer's fault, but still break the program:
		throw std::runtime_error("value not found");
	return iter;
}

// iterator can read and modify 
// const_iterator can only read and cannot modify 
// vector<int> vec = {10, 20, 30};

// vector<int>::iterator it = vec.begin();
// *it = 50; // Totally fine. vec is now {50, 20, 30}

// vector<int>::const_iterator cit = vec.cbegin();
// // *cit = 100; // ERROR! You cannot modify through a const_iterator.