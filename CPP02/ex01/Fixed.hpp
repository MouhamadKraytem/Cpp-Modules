/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkraytem <mkraytem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:05:52 by mkraytem          #+#    #+#             */
/*   Updated: 2024/09/24 13:31:39 by mkraytem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

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
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);



#endif