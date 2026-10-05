
#include "Fixed.hpp"
#include <iostream>

// int	main(void)
// {
// 	Fixed a;
// 	Fixed b (a);
// 	Fixed c;

// 	c = b;

// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
	
// 	b.setRawBits(42);
	
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
	
// 	return 0;
// }

int	main(void)
{
	Fixed a;
	// std::cout << "This is new 1"<< std::endl;
	
	Fixed b (a);

	// std::cout << "This is new 2 "<< std::endl;
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}