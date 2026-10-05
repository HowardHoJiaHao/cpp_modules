
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	std::cout << "  === testing random object and let derived class inherit it === " << std::endl;
	std::cout << " === testing generate() and  identify () === " <<std::endl;

	for (int i = 0; i < 10; i ++)
	{
		Base* ptr = generate();
		std::cout << "Test " << i + 1 << ": ";
		identify(*ptr);
		delete ptr;
	}

	std::cout << "\n === given the base class, figure out the underneath derive class ===" << std::endl;
	std::cout << "\n ===testing with known types === " << std::endl;

	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "A pointer: "; identify(a);
	std::cout << "A reference: "; identify(*a);
	std::cout << "B pointer: "; identify(b);
	std::cout << "B reference: "; identify(*b);
	std::cout << "C pointer: "; identify(c);
	std::cout << "C reference: "; identify(*c);
	
	delete a;
	delete b;
	delete c;

	return 0;
}