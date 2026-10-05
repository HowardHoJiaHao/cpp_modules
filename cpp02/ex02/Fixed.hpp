#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
    private:
        int _raw;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(int number);
        Fixed(float number);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        int getRawBits(void)const;
        void setRawBits(int number);
        int toInt(void) const;
        float toFloat(void) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // static no object instance needed
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& min( Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed& max( Fixed& a, Fixed& b); 
        
};

std::ostream &operator<<(std::ostream &out, const Fixed &number);

#endif