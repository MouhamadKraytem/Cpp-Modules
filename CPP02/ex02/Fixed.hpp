/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:05:52 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/24 18:58:39 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
    int toInt(void) const;

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

	Fixed &operator++();   // Pre-increment
	Fixed operator++(int); // Post-increment
	Fixed &operator--();   // Pre-decrement
	Fixed operator--(int); // Post-decrement

	static Fixed &min(Fixed &a, Fixed &b);               // Non-const version for min
    static const Fixed &min(const Fixed &a, const Fixed &b); // Const version for min
    static Fixed &max(Fixed &a, Fixed &b);               // Non-const version for max
    static const Fixed &max(const Fixed &a, const Fixed &b); // Const version for max
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);



#endif