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
	: ClapTrap(name)
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDmg = 20;
	std::cout << "constructor called, a ScavTrap object named " << name
	<< " has been constructed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj)
{
	std::cout << "copy constructor called for a ScavTrap object" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "destructor called, a ScavTrap object named " << this->m_name
            << " has been destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj) {
	if (this == &obj)
		return (*this);
	this->m_name = obj.m_name;
	this->m_hitPoints = obj.m_hitPoints;
	this->m_energyPoints = obj.m_energyPoints;
	this->m_attackDmg = obj.m_attackDmg;
	return (*this);
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is in Gate Keeper mode and is on high alert!" << std::endl;
}
