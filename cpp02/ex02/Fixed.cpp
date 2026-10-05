#include "Fixed.hpp"

Fixed::Fixed(void):_raw(0){}

Fixed::Fixed(int number)
{
    this->_raw = number << _fractionalBits;
}

Fixed::Fixed(float number)
{
    this->_raw = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_raw = other.getRawBits();
    return (*this);
}

Fixed::~Fixed(void){}

int Fixed::getRawBits(void) const
{
    return (_raw);
}

void Fixed::setRawBits(int number)
{
    this->_raw = number;
}

int Fixed::toInt(void) const
{
    return (_raw >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)_raw /(float)(1 << _fractionalBits));
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _raw = this->_raw + 1;
    return (temp); 
}

Fixed& Fixed::operator++ (void)
{
    _raw = this->_raw + 1;
    return (*this); 
}

// Prefix
// --a
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_raw =  this->_raw - 1;
    return (temp);
}

// Postfix
// a--
// If you returned a reference in the Postfix version, you would be returning a reference to temp.
// But temp is a local variable that dies the moment the function ends. 
// This leads to Dangling References
Fixed& Fixed::operator--(void)
{
    this->_raw = this->_raw - 1;
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    if (this->_raw > other._raw)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->_raw < other._raw)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->_raw >= other._raw)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->_raw <= other._raw)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->_raw == other._raw)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (this->_raw != other._raw)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed &other)const
{
    Fixed answer;
    answer._raw = this->_raw + other._raw;
    return (answer);
}


Fixed Fixed::operator-(const Fixed &other)const
{
    Fixed answer;
    answer._raw = this->_raw - other._raw;
    return (answer);
}


Fixed Fixed::operator*(const Fixed &other)const
{
    Fixed answer;
    long long temp = (this->_raw * other._raw);
    answer.setRawBits(temp >> _fractionalBits);
    return (answer);
}

// Your current code divides first, then shifts.
// This is a problem because integer division throws away the remainder immediately.
// If you divide $5 / 10$, you get $0$, and shifting $0$ still gives you $0$.
// The Fix: You must shift the numerator (the top number) before you divide. 
// This "inflates" the value so that after the division, the fractional parts are preserved.
Fixed Fixed::operator/(const Fixed &other)const
{
    Fixed answer;
    long long temp = (((long long)this->_raw << _fractionalBits )/ other._raw);
    answer.setRawBits(temp);
    return (answer);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (b);
    return (a);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &number)
{
    out << number.toFloat();
    return out;
}

