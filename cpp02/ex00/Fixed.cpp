
#include "Fixed.hpp"
#include <iostream>


Fixed::Fixed():_raw(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed& Fixed::operator=(const Fixed &others)
{
    if (this !=&others)
    {
        std::cout << "Copy assignation operator called" << std::endl;
        this->_raw = others.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}
