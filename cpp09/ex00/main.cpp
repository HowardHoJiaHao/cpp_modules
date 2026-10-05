#include <string>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Need one input file" << std::endl;
		return 1;
	}
	std::string file = av[1];
	BitcoinExchange	exchange(file);
	exchange.parseRate();
	exchange.processInput();
}
