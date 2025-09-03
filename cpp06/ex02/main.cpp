/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 17:56:28 by abhi              #+#    #+#             */
/*   Updated: 2025-08-10 17:56:28 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void)
{
	std::srand(std::time(0));
	int random = std::rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "Generated A" << std::endl;
		return (new A);
	case 1:
		std::cout << "Generated B" << std::endl;
		return (new B);
	case 2:
		std::cout << "Generated C" << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base *ptr)
{
	std::cout << "Class identified from pointer: ";
	if (dynamic_cast<A *>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "idk" << std::endl;
}

void identify(Base &ptr)
{
	std::cout << "Class identified by reference: ";
	try
	{
		(void)dynamic_cast<A &>(ptr);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B &>(ptr);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C &>(ptr);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}

// https://www.ibm.com/docs/pl/i/7.4.0?topic=operator-dynamic-casts-references
int main()
{
	Base *base;

	std::cout << "TEST" << std::endl;
	base = generate();
	identify(base);
	identify(*base);
	std::cout << std::endl;
	delete base;
	return (0);
}
