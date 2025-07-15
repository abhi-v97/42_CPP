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

FragTrap::FragTrap() : ClapTrap()
{
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDmg = 30;
	this->m_defaultHP = 100;
	this->m_defaultEnergy = 100;
	this->m_defaultDmg = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->m_name = name;
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDmg = 30;
	this->m_defaultHP = 100;
	this->m_defaultEnergy = 100;
	this->m_defaultDmg = 30;
	std::cout << "FragTrap constructor to construct object: " << name << std::endl;
}

FragTrap::FragTrap(FragTrap &obj) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for object: " << this->m_name << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &obj)
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

void FragTrap::attack(const std::string &target)
{
	if (this->m_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->m_name
				  << " can't attack target: FragTrap has been destroyed" << std::endl;
		return;
	}
	else if (this->m_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->m_name << " is out of energy! It cannot attack"
				  << std::endl;
	}
	else
	{
		this->m_energyPoints--;
		std::cout << "FragTrap " << this->m_name << " attacks " << target << "! Oh no!"
				  << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	if (this->m_hitPoints == 0)
		std::cout << "FragTrap " << this->m_name << " has been destroyed! But you pick up his hand from the debris and give him a high five. "
				  << std::endl;
	else
		std::cout << "FragTrap requests high fives from the guys. " << std::endl;
}
