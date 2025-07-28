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

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *meta = new Animal();
	const Animal *i = new Cat();
	const Animal *j = new Dog();
	std::cout << std::endl;

	std::cout << i->getType() << ": ";
	i->makeSound(); // will output the cat sound!
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << meta->getType() << ": ";
	meta->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	Animal a = Animal();
	a.makeSound();
	std::cout << std::endl;

	a = Cat();
	std::cout << a.getType() << ": ";
	a.makeSound();
	std::cout << std::endl;
	
	WrongAnimal *wa = new WrongAnimal();
	WrongAnimal *wb = new WrongCat();
	WrongCat *wc = new WrongCat();
	std::cout << std::endl;

	std::cout << wa->getType() << ": ";
	wa->makeSound();
	std::cout << wb->getType() << ": ";
	wb->makeSound();
	std::cout << wc->getType() << ": ";
	wc->makeSound();
	std::cout << std::endl;

	delete wa;
	delete wb;
	delete wc;
	std::cout << std::endl;

	return 0;
}
