/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-06 19:49:41 by abhi              #+#    #+#             */
/*   Updated: 2025-07-06 19:49:41 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDmg = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ScavTrap()
{
	std::cout << "constructor called, a ClapTrap object named " << name
	<< " has been constructed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj)
	: ClapTrap()
{
	
}

ScavTrap::~ScavTrap()
{
	
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj) {
	
	return (*this);
}

void ScavTrap::guardGate(void) {
	
}
