/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-25 17:40:23 by abhi              #+#    #+#             */
/*   Updated: 2025-06-25 17:40:23 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
	: m_name("DefaultName"), m_hitPoints(10), m_energyPoints(10),
	  m_attackDmg(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name)
	: m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDmg(0)
{
	std::cout << "constructor called, a ClapTrap object named " << name
			  << " has been constructed." << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "copy constructor called to create a ClapTrap object" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor called, a ClapTrap object named " << this->m_name
			  << " has been destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj)
{
	if (this == &obj)
		return (*this);
	this->m_name = obj.m_name;
	this->m_hitPoints = obj.m_hitPoints;
	this->m_energyPoints = obj.m_energyPoints;
	this->m_attackDmg = obj.m_attackDmg;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " can't attack target: ClapTrap has been destroyed"
				  << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " is out of energy! It cannot attack" << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "ClapTrap " << this->m_name << " attacks " << target
				  << "! Oh no!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints == 0)
		std::cout << "ClapTrap's " << this->m_name
				  << " health is already at zero, but sure, make it suffer" << std::endl;
	else if (this->m_hitPoints <= (int)amount)
	{
		this->m_hitPoints = 0;
		std::cout << "ClapTrap " << this->m_name << " takes " << amount
				  << " points of damage and is broken!" << std::endl;
	}
	else
	{
		this->m_hitPoints -= amount;
		std::cout << "ClapTrap " << this->m_name << " takes " << amount
				  << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " cannot repair itself; it is beyond repair!" << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->m_name << " cannot perform repairs; energy depleted!" << std::endl;
		return;
	}
	this->m_energyPoints--;
	if (this->m_hitPoints == defaultHitPoints)
	{
		std::cout << "ClapTrap " << this->m_name << " tries to repair itself at full heath! Silly ClapTrap."
				  << std::endl;
	}
	else if ((amount + this->m_hitPoints) >= defaultHitPoints)
	{
		this->m_hitPoints = defaultHitPoints;
		std::cout << "ClapTrap " << this->m_name << " repairs itself for " << amount
				  << " points and is back at full health!" << std::endl;
	}
	else
	{
		this->m_hitPoints += amount;
		std::cout << "ClapTrap " << this->m_name << " repairs itself for " << amount << " points." << std::endl;
	}
}

std::string ClapTrap::getName(void) const { return (this->m_name); }
unsigned int ClapTrap::getHitPoints(void) const { return (this->m_hitPoints); }
unsigned int ClapTrap::getEnergyPoints(void) const { return (this->m_energyPoints); }
unsigned int ClapTrap::getAttackDmg(void) const { return (this->m_attackDmg); }
