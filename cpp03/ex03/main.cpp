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
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dt1("DeeTee");
	std::cout << std::endl;
	
	// initial stats
	std::cout << "DiamondTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << dt1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << dt1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << dt1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << dt1.getAttackDmg() << std::endl;
	std::cout << std::endl;

	// member inheritance test
	dt1.highFivesGuys();
	dt1.guardGate();
	dt1.whoAmI();
	std::cout << std::endl;

	// repair at max health test
	dt1.beRepaired(99);
	std::cout << std::setw(20) << "Energy: " << dt1.getEnergyPoints()
			  << std::endl;
	std::cout << std::endl;

	// test taking damage and repairing itself
	dt1.attack("itself");
	dt1.takeDamage(30);
	std::cout << std::setw(20) << "HP: " << dt1.getHitPoints() << std::endl;
	dt1.beRepaired(10);
	std::cout << std::setw(20) << "HP: " << dt1.getHitPoints() << std::endl;
	std::cout << std::endl;

	// test running out of energy
	for (int i = 0; i < 10; i++)
		dt1.attack("Trappy");
	std::cout << std::endl;

	// test taking lethal damage, and trying to repair after...
	dt1.takeDamage(9999);
	dt1.takeDamage(9999);
	dt1.takeDamage(9999);
	dt1.takeDamage(9999);
	dt1.beRepaired(10);
	std::cout << std::endl;

	// member inheritance test
	dt1.highFivesGuys();
	dt1.guardGate();
	dt1.whoAmI();
	std::cout << std::endl;

	// post stats
	std::cout << "DiamondTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << dt1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << dt1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << dt1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << dt1.getAttackDmg() << std::endl;
	std::cout << std::endl;
	return (0);
}
