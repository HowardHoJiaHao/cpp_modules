#include "RPN.hpp"
#include <iostream>

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "not 2 argument" << std::endl;
		return 1;
	}
	// 3  3 + 2 2 +
	RPN calculate(av[1]);
	calculate.runInput();
	return 0;
}
