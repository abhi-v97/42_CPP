/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 20:26:50 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 20:26:50 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog() : AAnimal(), m_brain((new Brain()))
{
	std::cout << "Dog default constructor called" << std::endl;
	this->m_type = "Dog";
}

Dog::Dog(Dog const &obj) : AAnimal(), m_brain(NULL)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for " << this->m_type << std::endl;
	delete this->m_brain;
}

Dog &Dog::operator=(Dog const &obj)
{
	std::cout << "Dog operator overload called." << std::endl;
	if (this != &obj)
	{
		this->m_type = obj.m_type;
		if (this->m_brain != NULL)
			delete this->m_brain;
		this->m_brain = new Brain(*obj.m_brain);
	}
	return (*this);
}

Brain	*Dog::getBrain() const
{
	return (this->m_brain);
}

void Dog::makeSound() const
{
	std::cout << "Dog goes woof woof" << std::endl;
}
