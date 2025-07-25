/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-25 18:44:17 by abhi              #+#    #+#             */
/*   Updated: 2025-07-25 18:44:17 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Materia.hpp"
#include <iostream>

void subject_test(void)
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("Ice");
	me->equip(tmp);
	tmp = src->createMateria("Cure");
	me->equip(tmp);

	me->equip(src->createMateria("Cure"));
	me->equip(src->createMateria("Cure"));
	me->equip(src->createMateria("Cure"));

	tmp = src->createMateria("I DOESN'T exist");
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void my_test()
{
	// test that Materia source is a deep copy
	ICharacter *Cloud = new Character("Cloud");
	MateriaSource *bag1 = new MateriaSource();
	bag1->learnMateria(new Ice());
	MateriaSource *bag2 = new MateriaSource(*bag1);
	AMateria *ice = bag2->createMateria("Ice");
	Cloud->equip(ice);
	bag1->learnMateria(new Cure());
	AMateria *cure = bag2->createMateria("Cure");
	Cloud->equip(cure);
	std::cout << std::endl;
	
	// test bag limit
	bag1->learnMateria(new Materia("Fire"));
	bag1->learnMateria(new Materia("Lightning"));
	bag1->learnMateria(new Materia("Revive"));
	std::cout << std::endl;
	
	// test using materia
	AMateria *fire = bag1->createMateria("Fire");
	Cloud->equip(fire);
	Cloud->use(0, *Cloud);
	Cloud->use(1, *Cloud);
	Cloud->use(2, *Cloud);
	std::cout << std::endl;
	
	// test unequip
	Cloud->unequip(1);
	Cloud->unequip(42);
	Cloud->use(1, *Cloud);
	std::cout << std::endl;

	delete Cloud;
	delete bag1;
	delete bag2;
	delete fire;
}

int main(void)
{
	subject_test();
	std::cout << std::endl;
	my_test();
	return 0;
}
