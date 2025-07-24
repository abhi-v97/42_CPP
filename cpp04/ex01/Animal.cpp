/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 15:04:52 by abhi              #+#    #+#             */
/*   Updated: 2025-07-18 15:04:52 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : m_type("Unknown animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal::Animal(std::string &name) : m_type("Animal")
{
	std::cout << "Animal constructor called for " << name << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called for " << this->m_type << std::endl;
}

Animal &Animal::operator=(Animal const &obj)
{
	std::cout << "Animal operator overload called." << std::endl;
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

std::string const &Animal::getType() const
{
	return (this->m_type);
}

void Animal::setType(const std::string &type_)
{
	this->m_type = type_;
	return;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal noises" << std::endl;
}
