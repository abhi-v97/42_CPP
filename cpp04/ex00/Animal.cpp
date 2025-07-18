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

Animal::Animal()
	: type("Animal")
{
	std::cout << "Default constructor for class Animal" << std::endl;
}

Animal::Animal(std::string name)
	: type("Animal")
{
	std::cout << "Constructor for class Animal; type: " << name << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor for class Animal: " << this->type << std::endl;
}

void Animal::makeSound() {
	std::cout << "Generic animal noises" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::setType(const std::string &type_) {
	this->type = type_;
	return ;
}
