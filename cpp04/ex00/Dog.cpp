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
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Default constructor for class Dog" << std::endl;
}

Dog::Dog(std::string name) : Animal()
{
	std::cout << "Constructor for object Dog: " << name << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor for class Dog" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "Woof woof" << std::endl;
}
