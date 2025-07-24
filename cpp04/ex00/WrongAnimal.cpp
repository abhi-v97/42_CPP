/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 19:34:33 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 19:34:33 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : m_type("Unknown WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal::WrongAnimal(std::string const &type) : m_type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called for " << type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called for " << this->m_type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal operator overload called." << std::endl;
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

std::string const &WrongAnimal::getType() const
{
	return (this->m_type);
}

void WrongAnimal::setType(const std::string &type_)
{
	this->m_type = type_;
	return;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Generic WrongAnimal noises" << std::endl;
}
