/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:06:38 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/24 18:59:22 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << _fractionalBits));
}

// Converts to integer
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits; // Shifts right by 8 bits to get the integer part
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointValue == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	
	Fixed result;
	result.setRawBits((this->_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	return result;
}

Fixed &Fixed::operator++()
{
	_fixedPointValue++; // Increment the raw fixed-point value by 1
	return *this;		// Return the incremented object
}

// Post-increment
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);	// Store the current value
	_fixedPointValue++; // Increment the raw fixed-point value by 1
	return temp;		// Return the original (non-incremented) value
}

// Pre-decrement
Fixed &Fixed::operator--()
{
	_fixedPointValue--; // Decrement the raw fixed-point value by 1
	return *this;		// Return the decremented object
}

// Post-decrement
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);	// Store the current value
	_fixedPointValue--; // Decrement the raw fixed-point value by 1
	return temp;		// Return the original (non-decremented) value
}

// Non-const version of min
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

// Const version of min
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

// Non-const version of max
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

// Const version of max
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat(); // Output the floating-point representation
	return os;			   // Return the output stream object
}