/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:38:35 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:38:35 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap st1("Scrappy");
	ClapTrap ct2("Clappy");
	std::cout << std::endl;

	// initial stats
	std::cout << "ScavTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << st1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << st1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << st1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << st1.getAttackDmg() << std::endl;
	std::cout << std::endl;

	// ct2 stats
	std::cout << "ClapTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << ct2.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << ct2.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << ct2.getEnergyPoints()
				<< std::endl;
	std::cout << std::setw(20) << "Attack: " << ct2.getAttackDmg() << std::endl;
	std::cout << std::endl;

	// guard gate test
	st1.guardGate();
	std::cout << std::endl;

	// repair at max health test
	st1.beRepaired(99);
	std::cout << std::setw(20) << "HP: " << st1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << st1.getEnergyPoints()
			  << std::endl;
	std::cout << std::endl;

	// test taking damage and repairing itself
	ct2.attack("Clappy");
	std::cout << std::setw(20) << "HP: " << st1.getHitPoints() << std::endl;
	st1.takeDamage(30);
	std::cout << std::setw(20) << "HP: " << st1.getHitPoints() << std::endl;
	st1.beRepaired(10);
	std::cout << std::endl;

	// test running out of energy
	for (int i = 0; i < 10; i++)
		st1.attack("Trappy");
	std::cout << std::endl;

	// test taking lethal damage, and trying to repair after...
	ct2.attack("Trappy");
	st1.takeDamage(9999);
	st1.takeDamage(9999);
	st1.takeDamage(9999);
	st1.takeDamage(9999);
	st1.beRepaired(10);
	std::cout << std::endl;

	// guard gate test
	st1.guardGate();
	std::cout << std::endl;

	// post stats
	std::cout << "ClapTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << st1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << st1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << st1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << st1.getAttackDmg() << std::endl;
	std::cout << std::endl;
	return (0);
}
