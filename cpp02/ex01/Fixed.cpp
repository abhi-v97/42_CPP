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

// constructors and destructors

Fixed::Fixed() : m_raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

// n * 256 is equivalent to n << m_fractionalBits (n << 8)
Fixed::Fixed(const int n) : m_raw(n << m_fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// can't bitshift a float directly, so you bitshift 1 instead
Fixed::Fixed(const float f) : m_raw(roundf(f * (1 << m_fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// operator overload

Fixed &Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->m_raw = src.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &outf, const Fixed &obj) {
	outf << obj.toFloat();
	return (outf);
}

// getters and setters

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->m_raw);
}

void Fixed::setRawBits(int const raw) {
	this->m_raw = raw;
}

// member functions

int Fixed::toInt(void) const {
	return (this->m_raw >> this->m_fractionalBits);
}

float Fixed::toFloat(void) const { 
	return ((float)m_raw / (1 << m_fractionalBits)); 
}
