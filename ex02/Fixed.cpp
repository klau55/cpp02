#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _fixedValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int param) {
    std::cout << "Int constructor called" << std::endl;
    _fixedValue = param << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float param) {
    std::cout << "Float constructor called" << std::endl;
    _fixedValue = roundf(param * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedValue = other._fixedValue;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// getRawBits
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedValue;
}

// setRawBits
void Fixed::setRawBits(int const raw) {
    this->_fixedValue = raw;
}

// Conversion to float
float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedValue) / (1 << _fractionalBits);
}

// Conversion to int
int Fixed::toInt(void) const {
    return this->_fixedValue >> _fractionalBits;
}

// Overload of insertion (<<) operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}

// Comparison Operators
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedValue > other._fixedValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedValue < other._fixedValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedValue >= other._fixedValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedValue <= other._fixedValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedValue == other._fixedValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedValue != other._fixedValue;
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._fixedValue = this->_fixedValue + other._fixedValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._fixedValue = this->_fixedValue - other._fixedValue;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long temp = static_cast<long>(this->_fixedValue) * static_cast<long>(other._fixedValue);
    result._fixedValue = static_cast<int>(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    if (other._fixedValue == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        result._fixedValue = 0;
        return result;
    }
    long temp = (static_cast<long>(this->_fixedValue) << _fractionalBits) / static_cast<long>(other._fixedValue);
    result._fixedValue = static_cast<int>(temp);
    return result;
}

// Pre-Increment
Fixed &Fixed::operator++() { // ++a
    this->_fixedValue++;
    return *this;
}

// Post-Increment
Fixed Fixed::operator++(int) { // a++
    Fixed temp(*this);
    this->_fixedValue++;
    return temp;
}

// Pre-Decrement
Fixed &Fixed::operator--() { // --a
    this->_fixedValue--;
    return *this;
}

// Post-Decrement
Fixed Fixed::operator--(int) { // a--
    Fixed temp(*this);
    this->_fixedValue--;
    return temp;
}

// Static Member Functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
