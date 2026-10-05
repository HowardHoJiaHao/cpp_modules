
#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed():_raw(0)
{
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int number):_raw(number)
{
    std::cout << "Int constructor called" << std::endl;
    this->_raw = number << this->_fractionalBits;
};

// float x float return float number 
// roundf is the one make it to int
Fixed::Fixed(float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->_raw = roundf(number * (1 << _fractionalBits));
};

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this=other;
};

Fixed& Fixed::operator=(const Fixed &others)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &others)
        this->_raw = others._raw;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

float Fixed::toFloat(void) const
{
    return ((float)this->_raw / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return this->_raw >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}

std::ostream& operator<<(std::ostream &out, const Fixed &number)
{
    out << number.toFloat();
    return (out); 
}
