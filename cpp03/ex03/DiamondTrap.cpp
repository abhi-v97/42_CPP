/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 07:28:38 by abhi              #+#    #+#             */
/*   Updated: 2025-07-15 07:28:38 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap("DT_clap_trap")
{
	this->m_name = "DT";
	this->m_hitPoints = FragTrap::defaultHP;
	this->m_energyPoints = ScavTrap::defaultEnergy;
	this->m_attackDmg = FragTrap::defaultDmg;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->m_name = name;
	this->m_hitPoints = FragTrap::defaultHP;
	this->m_energyPoints = ScavTrap::defaultEnergy;
	this->m_attackDmg = FragTrap::defaultDmg;
	std::cout << "DiamondTrap constructor to construct object: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for object: " << this->m_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &obj)
{
	if (this == &obj)
		return (*this);
	this->m_name = obj.m_name;
	this->m_hitPoints = obj.m_hitPoints;
	this->m_energyPoints = obj.m_energyPoints;
	this->m_attackDmg = obj.m_attackDmg;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "DiamondTrap has been destroyed!" << std::endl;
		return ;
	}
	std::cout << "I am the mighty DiamondTrap " << this->m_name << "!" << std::endl;
	std::cout << "My ClapTrap designation before modifications was " << this->ClapTrap::m_name
			 << ". " << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints == 0)
		std::cout << "DiamondTrap " << this->m_name
				  << " health is already at zero, but sure, make it suffer" << std::endl;
	else if (this->m_hitPoints <= (int)amount)
	{
		this->m_hitPoints = 0;
		std::cout << "DiamondTrap " << this->m_name << " takes " << amount
				  << " points of damage and is broken!" << std::endl;
	}
	else
	{
		this->m_hitPoints -= amount;
		std::cout << "DiamondTrap " << this->m_name << " takes " << amount << " points of damage!"
				  << std::endl;
	}
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "DiamondTrap " << this->m_name << " cannot repair itself; it is beyond repair!"
				  << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "DiamondTrap " << this->m_name << " cannot perform repairs; energy depleted!"
				  << std::endl;
		return;
	}
	this->m_energyPoints--;
	if (this->m_hitPoints == defaultHP)
	{
		std::cout << "DiamondTrap " << this->m_name
				  << " tries to repair itself at full heath! Silly DiamondTrap." << std::endl;
	}
	else if ((amount + this->m_hitPoints) >= defaultHP)
	{
		this->m_hitPoints = defaultHP;
		std::cout << "DiamondTrap " << this->m_name << " repairs itself for " << amount
				  << " points and is back at full health!" << std::endl;
	}
	else
	{
		this->m_hitPoints += amount;
		std::cout << "DiamondTrap " << this->m_name << " repairs itself for " << amount << " points."
				  << std::endl;
	}
}


std::string DiamondTrap::getName(void) const {
	return (this->m_name);
}
