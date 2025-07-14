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
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap	st1("scavTrap1");
	
	std::cout << "st1 attack: " << st1.getAttackDmg() << std::endl;
	std::cout << "st1 energy: " << st1.getEnergyPoints() << std::endl;
	std::cout << "st1 HP: " << st1.getHitPoints() << std::endl;
	st1.guardGate();
	return (0);
}
