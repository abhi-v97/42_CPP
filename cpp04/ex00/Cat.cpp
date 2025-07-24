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
#include <string>
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->m_type = "Cat";
}

Cat::Cat(Cat const &obj) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for " << this->m_type << std::endl;
}

Cat &Cat::operator=(Cat const &obj)
{
	std::cout << "Cat operator overload called." << std::endl;
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat goes meow meow" << std::endl;
}
