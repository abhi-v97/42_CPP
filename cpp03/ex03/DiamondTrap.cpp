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
	this->m_hitPoints = FragTrap::m_defaultHP;
	this->m_energyPoints = ScavTrap::m_defaultEnergy;
	this->m_attackDmg = FragTrap::m_defaultDmg;
	this->m_defaultHP = FragTrap::m_defaultHP;
	this->m_defaultEnergy = ScavTrap::m_defaultEnergy;
	this->m_defaultDmg = FragTrap::m_defaultDmg;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->m_name = name;
	this->m_hitPoints = FragTrap::m_defaultHP;
	this->m_energyPoints = ScavTrap::m_defaultEnergy;
	this->m_attackDmg = FragTrap::m_defaultDmg;
	this->m_defaultHP = FragTrap::m_defaultHP;
	this->m_defaultEnergy = ScavTrap::m_defaultEnergy;
	this->m_defaultDmg = FragTrap::m_defaultDmg;
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
	this->m_defaultHP = obj.m_defaultHP;
	this->m_defaultEnergy = obj.m_defaultEnergy;
	this->m_defaultDmg = obj.m_defaultDmg;
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "whoAmI failed, DiamondTrap has been destroyed!" << std::endl;
		return ;
	}
	std::cout << "I am DiamondTrap " << this->m_name << "!" << std::endl;
	std::cout << "My ClapTrap designation before modifications was " << this->ClapTrap::m_name
			 << ". " << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName(void) const {
	return (this->m_name);
}
