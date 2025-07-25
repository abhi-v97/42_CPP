/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 15:10:37 by abhi              #+#    #+#             */
/*   Updated: 2025-07-18 15:10:37 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->m_type = "Dog";
}

Dog::Dog(Dog const &obj) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for " << this->m_type << std::endl;
}

Dog &Dog::operator=(Dog const &obj)
{
	std::cout << "Dog operator overload called." << std::endl;
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog goes woof woof" << std::endl;
}
