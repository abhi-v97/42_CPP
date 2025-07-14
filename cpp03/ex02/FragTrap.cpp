/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-14 14:07:27 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-14 14:07:27 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDmg = 20;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	this->m_name = name;
	this->m_hitPoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDmg = 20;
	std::cout << "constructor called, a FragTrap object named " << name
	<< " has been constructed." << std::endl;
}

FragTrap::FragTrap(FragTrap &obj)
{
	std::cout << "copy constructor called for a FragTrap object" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "destructor called, a FragTrap object named " << this->m_name
            << " has been destroyed." << std::endl;
}


void FragTrap::attack(const std::string &target)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->m_name << " can't attack target: FragTrap has been destroyed"
				  << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->m_name << " is out of energy! It cannot attack" << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "FragTrap " << this->m_name << " attacks " << target
				  << "! Oh no!" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints == 0)
		std::cout << "FragTrap's " << this->m_name
				  << " health is already at zero, but sure, make it suffer" << std::endl;
	else if (this->m_hitPoints <= (int)amount)
	{
		this->m_hitPoints = 0;
		std::cout << "FragTrap " << this->m_name << " takes " << amount
				  << " points of damage and is broken!" << std::endl;
	}
	else
	{
		this->m_hitPoints -= amount;
		std::cout << "FragTrap " << this->m_name << " takes " << amount
				  << " points of damage!" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->m_name << " cannot repair itself; it is beyond repair!" << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->m_name << " cannot perform repairs; energy depleted!" << std::endl;
		return;
	}
	this->m_energyPoints--;
	if (this->m_hitPoints == defaultHitPoints)
	{
		std::cout << "FragTrap " << this->m_name << " tries to repair itself at full heath! Silly FragTrap."
				  << std::endl;
	}
	else if ((amount + this->m_hitPoints) >= defaultHitPoints)
	{
		this->m_hitPoints = defaultHitPoints;
		std::cout << "FragTrap " << this->m_name << " repairs itself for " << amount
				  << " points and is back at full health!" << std::endl;
	}
	else
	{
		this->m_hitPoints += amount;
		std::cout << "FragTrap " << this->m_name << " repairs itself for " << amount << " points." << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High five requested!" << std::endl;
}


FragTrap &FragTrap::operator=(FragTrap &obj) {
	if (this == &obj)
		return (*this);
	this->m_name = obj.m_name;
	this->m_hitPoints = obj.m_hitPoints;
	this->m_energyPoints = obj.m_energyPoints;
	this->m_attackDmg = obj.m_attackDmg;
	return (*this);
}
