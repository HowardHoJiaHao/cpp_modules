#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
 
class Fixed
{
    private:
        int _raw;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(int number);
        Fixed(float number);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        float toFloat( void ) const;
        int toInt (void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed &number);

#endif