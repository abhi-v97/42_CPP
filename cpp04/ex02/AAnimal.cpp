/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 15:04:52 by abhi              #+#    #+#             */
/*   Updated: 2025-07-18 15:04:52 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : m_type("Unkown Aanimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = obj;
}

AAnimal::AAnimal(std::string &name) : m_type("AAnimal")
{
	std::cout << "AAnimal constructor called for " << name << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called for " << this->m_type << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &obj)
{
	std::cout << "AAnimal operator overload called." << std::endl;
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

std::string const &AAnimal::getType() const
{
	return (this->m_type);
}

void AAnimal::setType(const std::string &type_)
{
	this->m_type = type_;
	return;
}

void AAnimal::makeSound() const
{
	std::cout << "Generic Aanimal noises" << std::endl;
}
