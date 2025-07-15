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
	this->m_hitPoints = defaultHP;
	this->m_energyPoints = defaultEnergy;
	this->m_attackDmg = defaultDmg;
	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->m_name = name;
	this->m_hitPoints = defaultHP;
	this->m_energyPoints = defaultEnergy;
	this->m_attackDmg = defaultDmg;
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints == 0)
		std::cout << "ScavTrap " << this->m_name
				  << " health is already at zero, but sure, make it suffer" << std::endl;
	else if (this->m_hitPoints <= (int)amount)
	{
		this->m_hitPoints = 0;
		std::cout << "ScavTrap " << this->m_name << " takes " << amount
				  << " points of damage and is broken!" << std::endl;
	}
	else
	{
		this->m_hitPoints -= amount;
		std::cout << "ScavTrap " << this->m_name << " takes " << amount << " points of damage!"
				  << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->m_name << " cannot repair itself; it is beyond repair!"
				  << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->m_name << " cannot perform repairs; energy depleted!"
				  << std::endl;
		return;
	}
	this->m_energyPoints--;
	if (this->m_hitPoints == defaultHP)
	{
		std::cout << "ScavTrap " << this->m_name
				  << " tries to repair itself at full heath! Silly ScavTrap." << std::endl;
	}
	else if ((amount + this->m_hitPoints) >= defaultHP)
	{
		this->m_hitPoints = defaultHP;
		std::cout << "ScavTrap " << this->m_name << " repairs itself for " << amount
				  << " points and is back at full health!" << std::endl;
	}
	else
	{
		this->m_hitPoints += amount;
		std::cout << "ScavTrap " << this->m_name << " repairs itself for " << amount << " points."
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
