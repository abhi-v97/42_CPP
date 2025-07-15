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
#include "FragTrap.hpp"

int main(void)
{
	FragTrap ft1("Freddy");
	ScavTrap st1("Scrappy");
	std::cout << std::endl;

	// initial stats
	std::cout << "FragTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << ft1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << ft1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << ft1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << ft1.getAttackDmg() << std::endl;
	std::cout << std::endl;

	// st1 stats
	std::cout << "ScavTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << st1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << st1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << st1.getEnergyPoints()
				<< std::endl;
	std::cout << std::setw(20) << "Attack: " << st1.getAttackDmg() << std::endl;
	std::cout << std::endl;

	// high five test
	ft1.highFivesGuys();
	std::cout << std::endl;

	// repair at max health test
	ft1.beRepaired(99);
	std::cout << std::setw(20) << "Energy: " << ft1.getEnergyPoints()
			  << std::endl;
	std::cout << std::endl;

	// test taking damage and repairing itself
	st1.attack("Clappy");
	ft1.takeDamage(30);
	std::cout << std::setw(20) << "HP: " << ft1.getHitPoints() << std::endl;
	ft1.beRepaired(10);
	std::cout << std::setw(20) << "HP: " << ft1.getHitPoints() << std::endl;
	std::cout << std::endl;

	// test running out of energy
	for (int i = 0; i < 10; i++)
		ft1.attack("Trappy");
	std::cout << std::endl;

	// test taking lethal damage, and trying to repair after...
	st1.attack("Trappy");
	ft1.takeDamage(9999);
	ft1.takeDamage(9999);
	ft1.takeDamage(9999);
	ft1.takeDamage(9999);
	ft1.beRepaired(10);
	std::cout << std::endl;

	// high five test
	ft1.highFivesGuys();
	std::cout << std::endl;

	// post stats
	std::cout << "FragTrap stats: " << std::endl;
	std::cout << std::setw(20) << "Designation: " << ft1.getName() << std::endl;
	std::cout << std::setw(20) << "HP: " << ft1.getHitPoints() << std::endl;
	std::cout << std::setw(20) << "Energy: " << ft1.getEnergyPoints()
			  << std::endl;
	std::cout << std::setw(20) << "Attack: " << ft1.getAttackDmg() << std::endl;
	std::cout << std::endl;
	return (0);
}
