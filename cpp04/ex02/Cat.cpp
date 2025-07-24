/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 19:10:11 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 19:10:11 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Cat::Cat() : AAnimal(), m_brain((new Brain()))
{
	std::cout << "Cat default constructor called" << std::endl;
	this->m_type = "Cat";
}

Cat::Cat(Cat const &obj) : AAnimal(), m_brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for " << this->m_type << std::endl;
	delete this->m_brain;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Cat operator overload called." << std::endl;
	if (this != &obj)
	{
		this->m_type = obj.m_type;
		if (this->m_brain != NULL)
			delete this->m_brain;
		this->m_brain = new Brain(*obj.m_brain);
	}
	return (*this);
}

Brain	*Cat::getBrain() const
{
	return (this->m_brain);
}

void Cat::makeSound() const
{
	std::cout << "Cat goes meow meow" << std::endl;
}
