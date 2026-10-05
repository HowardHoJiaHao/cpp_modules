
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a; //_raw = 0
	Fixed	const b( Fixed(5.05f) * Fixed (2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl; //_raw = 1 , so toFloat = 1 / 256 = 0.00390625
	std::cout << a << std::endl;
	std::cout << a++ << std::endl; //print old value, _raw = 1, toFloat = 0.00390625
	std::cout << a << std::endl; // _now _raw = 2, toFloat = 2/256 = 0.0078125
	std::cout << b << std::endl; // 5.05 * 2 = 10.10

	std::cout << Fixed::max (a, b) << std::endl; //b is bigger

	std::cout << "\n --- comparison tests ---" << std::endl;

	Fixed x(10);
	Fixed y(42);

	std::cout << "x: " << x << " y: " << y <<std::endl;
	std::cout << "x < y : " << (x < y) << std::endl;
	std::cout << "x > y : " << (x > y) << std::endl;
	std::cout << "x <= y : " << (x <= y) << std::endl;
	std::cout << "x >= y : " << (x >= y) << std::endl;
	std::cout << "x == y : " << (x == y) << std::endl;
	std::cout << "x != y : " << (x != y) << std::endl;

	std::cout << "\n --- Arithmetic tests --- " << std::endl;

	Fixed p(2.5f);
	Fixed q(1.25f); // not 0: the subject allows a division by 0 to crash

	std::cout << "p: " << p << " q: " << q << std::endl;
	std::cout << "p + q = " << (p + q) << std::endl;
	std::cout << "p - q = " << (p - q) << std::endl;
	std::cout << "p * q = " << (p * q) << std::endl;
	std::cout << "p / q = " << (p / q) << std::endl;

	std::cout << "\n--- Increment/Decrement test ---" << std::endl;

	Fixed z(1.0f);

	std::cout << "z	: " << z << std::endl; // 257/256
	std::cout << "++z	: " << ++z << std::endl; //so what it increased, it increase the _raw by 1
	std::cout << "z	: " << z << std::endl;
	std::cout << "z++	: " << z++ << std::endl;
	std::cout << "z	: " << z << std::endl;
	std::cout << "--z	: " << --z << std::endl;
	std::cout << "z	: " << z << std::endl;
	std::cout << "z--	: " << z-- << std::endl;
	std::cout << "z	: " << z << std::endl;

	std::cout << "\n --- min/max tests --- " << std::endl;

	Fixed m(7.5f);
	Fixed n(7.6f);

	std::cout << "min(m, n) = " << Fixed::min(m, n) << std::endl;
	std::cout << "max(m, n) = " << Fixed::max(m, n) << std::endl;

	const Fixed cm(100);
	const Fixed cn(50);

	std::cout << "const min = " << Fixed::min(cm, cn) << std::endl;
	std::cout << "const max = " << Fixed::max(cm, cn) << std::endl;


	return 0;
}
