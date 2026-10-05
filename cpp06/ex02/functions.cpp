#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// dynamic_cast is a C++ operator used for safe type conversion between pointers or references to polymorphic classes (classes with at least one virtual function).
// It checks at runtime whether the conversion is valid:
// For pointers: If the cast is valid, it returns a pointer to the derived type; if not, it returns nullptr.
// For references: If the cast is valid, it returns a reference to the derived type; if not, it throws std::bad_cast.

// srand(seed) sets the initial internal state (seed).
// rand() uses that state and advances it each call.
// rand() does not “set a new seed” directly, it just moves generator state forward.
// If you never call srand, rand() still works, but starts from default implementation-defined seed/state (often deterministic each run).

Base* generate(void)
{
	static bool isSeeded = false;
	int random;

	if (!isSeeded) 
	{
		std::srand(std::time(NULL));
		isSeeded = true;
	}
	random = std::rand() % 3;
	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base * p)
{
	if (p == NULL)
	{
		std::cout << "NULL Pointer" << std::endl;
		return;
	}
	// dynamic_cast tries to safely convert a base-class type to a derived-class type at runtime.
	if (dynamic_cast<A*>(p) != NULL) //(3)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		// A* a = dynamic_cast<A*>(p);
		// A& a = dynamic_cast<A&>(p);
		// (void) means “I intentionally ignore the returned value.”
		(void) dynamic_cast<A&>(p); // throw std::bad_cast
		std::cout << "A" << std::endl;
		return;
	}
	catch(...){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(...){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(...){}

	std::cout << "Unknown type" << std::endl;
}