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

ScavTrap::ScavTrap() : ClapTrap()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDmg = 20;
	this->m_defaultHP = 100;
	this->m_defaultEnergy = 50;
	this->m_defaultDmg = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->m_name = name;
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDmg = 20;
	this->m_defaultHP = 100;
	this->m_defaultEnergy = 50;
	this->m_defaultDmg = 20;
	std::cout << "ScavTrap constructor to construct object: " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for object: " << this->m_name << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj)
{
	if (this == &obj)
		return (*this);
	this->m_name = obj.m_name;
	this->m_hitPoints = obj.m_hitPoints;
	this->m_energyPoints = obj.m_energyPoints;
	this->m_attackDmg = obj.m_attackDmg;
	this->m_defaultHP = obj.m_defaultHP;
	this->m_defaultEnergy = obj.m_defaultEnergy;
	this->m_defaultDmg = obj.m_defaultDmg;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->m_name
				  << " can't attack target: ScavTrap has been destroyed" << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->m_name << " is out of energy! It cannot attack"
				  << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << "! Oh no!"
				  << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	if (this->m_hitPoints == 0)
		std::cout << "ScavTrap " << this->m_name << " has been decimated and cannot guard the gate!"
				  << std::endl;
	else
		std::cout << "ScavTrap is in Gate Keeper mode; it is on high alert!" << std::endl;
}
