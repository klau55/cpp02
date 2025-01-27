#include "Fixed.hpp"
#include <cmath> // roundf

Fixed::Fixed() : _fixedValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int param) {
    std::cout << "Int constructor called" << std::endl;
    _fixedValue = param << _fractionalBits;
}

Fixed::Fixed(const float param) {
    std::cout << "Float constructor called" << std::endl;
    _fixedValue = (int)roundf(param * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedValue = other._fixedValue;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    // (same as ex00, optionally print a message if you like)
    return _fixedValue;
}

void Fixed::setRawBits(int const raw) {
    // (same as ex00)
    _fixedValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)_fixedValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedValue >> _fractionalBits;
}

// Overload <<
std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}
