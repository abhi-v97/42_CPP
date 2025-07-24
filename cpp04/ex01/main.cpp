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
#include <iostream>

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;
	
	// test that brain has been deep copied
	Brain *brain1 = new Brain();
	brain1->setIdeas(0, "Good idea");
	std::cout << "brain1 idea: " << brain1->getIdeas(0) << std::endl;
	std::cout << std::endl;

	Brain *brain2 = new Brain();
	*brain2 = *brain1;
	std::cout << "brain2 idea: " << brain2->getIdeas(0) << std::endl;
	std::cout << std::endl;
	
	brain2->setIdeas(0, "Bad idea");
	std::cout << "brain1 idea: " << brain1->getIdeas(0) << std::endl;
	std::cout << "brain2 idea: " << brain2->getIdeas(0) << std::endl;
	std::cout << std::endl;

	delete brain1;
	delete brain2;
	std::cout << std::endl;
	
	// test that dog has been deep copied
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog(*dog1);
	std::cout << std::endl;
	
	dog1->getBrain()->setIdeas(0, "Great idea");
	std::cout << "dog1 idea: " << dog1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "dog2 idea: " << dog2->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;

	dog2->getBrain()->setIdeas(0, "Terrible idea");
	std::cout << "dog1 idea: " << dog1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "dog2 idea: " << dog2->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;

	delete dog1;
	delete dog2;
	std::cout << std::endl;

	return (0);
}
