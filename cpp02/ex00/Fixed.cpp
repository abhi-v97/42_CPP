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

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &cpy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->m_raw);
}

void Fixed::setRawBits(int const raw) {
	this->m_raw = raw;
}
