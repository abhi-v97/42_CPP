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

#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int main(void)
{
	ClapTrap ct1("Clappy");
	ClapTrap ct2("Trappy");
	std::cout << std::endl;

	// initial stats
	std::cout << "ClapTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << ct1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << ct1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << ct1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << ct1.getAttackDmg() << std::endl;
	std::cout << std::endl;

	// repair at max health test
	ct1.beRepaired(99);
	std::cout << std::setw(20) << "Energy: " << ct1.getEnergyPoints()
			  << std::endl;
	std::cout << std::endl;

	// test taking damage and repairing itself
	ct2.attack("Clappy");
	ct1.takeDamage(3);
	std::cout << std::setw(20) << "HP: " << ct1.getHitPoints() << std::endl;
	ct1.beRepaired(10);
	std::cout << std::setw(20) << "HP: " << ct1.getHitPoints() << std::endl;
	std::cout << std::endl;

	// test running out of energy
	for (int i = 0; i < 10; i++)
		ct1.attack("Trappy");
	std::cout << std::endl;

	// test taking lethal damage, and trying to repair after...
	ct2.attack("Trappy");
	ct1.takeDamage(9999);
	ct1.takeDamage(9999);
	ct1.takeDamage(9999);
	ct1.takeDamage(9999);
	ct1.beRepaired(10);
	std::cout << std::endl;

	std::cout << "ClapTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << ct1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << ct1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << ct1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << ct1.getAttackDmg() << std::endl;
	std::cout << std::endl;
	return (0);
}
