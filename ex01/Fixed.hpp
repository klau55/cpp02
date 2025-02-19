#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _fixedValue;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();                   // Default constructor
    Fixed(const Fixed &other); // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment
    ~Fixed();                  // Destructor

    // New constructors
    Fixed(const int param);
    Fixed(const float param);

    // Conversion methods
    float toFloat(void) const;
    int   toInt(void) const;

    // Getters/Setters
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

// Overload of insertion (<<) operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
