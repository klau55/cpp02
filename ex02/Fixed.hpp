#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _fixedValue;                    // Stores the fixed-point number
    static const int    _fractionalBits = 8;            // Number of fractional bits

public:
    // Orthodox Canonical Form
    Fixed();                                    // Default constructor
    Fixed(const Fixed &other);                  // Copy constructor
    Fixed &operator=(const Fixed &other);       // Copy assignment operator
    ~Fixed();                                   // Destructor

    // New Constructors
    Fixed(const int param);                     // Int constructor
    Fixed(const float param);                   // Float constructor

    // Conversion Methods
    float toFloat(void) const;                  // Convert to float
    int   toInt(void) const;                    // Convert to int

    // Accessors
    int  getRawBits(void) const;
    void setRawBits(int const raw);

    // Comparison Operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment/Decrement Operators
    // Pre-Increment
    Fixed &operator++();    // ++a
    Fixed &operator--();    // --a

    // Post-Increment
    Fixed operator++(int);  // a++
    Fixed operator--(int);  // a--

    // Static Member Functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Overload of insertion (<<) operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif
