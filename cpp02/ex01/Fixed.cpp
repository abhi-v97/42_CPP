/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-16 19:28:51 by abhi              #+#    #+#             */
/*   Updated: 2025-06-16 19:28:51 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

// n * 256 is equivalent to n << m_fractionalBits (n << 8)
Fixed::Fixed(const int n) : m_raw(n * 256) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : m_raw(roundf(f * 256)) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->setRawBits(src.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->m_raw);
}

void Fixed::setRawBits(int const raw) {
	this->m_raw = raw;
}

int Fixed::toInt(void) const {
	return (this->getRawBits() >> this->m_fractionalBits);
}

// 256: 2^8, there's 8 fractional bits
float Fixed::toFloat(void) const { return ((float)m_raw / 256); }

std::ostream &operator<<(std::ostream &outf, const Fixed &obj) {
	outf << obj.toFloat();
	return (outf);
}
