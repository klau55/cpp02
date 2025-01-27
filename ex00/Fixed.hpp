#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _fixedValue;                   // to store the fixed-point number
    static const int    _fractionalBits = 8;           // number of fractional bits (8)

public:
    // 1. Default constructor
    Fixed();

    // 2. Copy constructor
    Fixed(const Fixed &other);

    // 3. Copy assignment operator
    Fixed &operator=(const Fixed &other);

    // 4. Destructor
    ~Fixed();

    // Accessors
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif