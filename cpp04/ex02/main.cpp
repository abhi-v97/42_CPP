/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 19:40:47 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 19:40:47 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	// will not compile, AAnimal is an abstract class
	// AAnimal *animal = new AAnimal();

	AAnimal *dog = new Dog();
	dog->makeSound();
	std::cout << std::endl;

	delete dog;
	return 0;
}
