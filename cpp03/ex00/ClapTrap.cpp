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
      m_attackDmg(0) {
  std::cout << "default constructor called." << std::endl;
  return;
}

ClapTrap::ClapTrap(std::string name)
    : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDmg(0) {
  std::cout << "constructor called, a ClapTrap object named " << name
            << "has been constructed." << std::endl;
  return;
}

void ClapTrap::attack(const std::string &target) {
  if (this->m_hitPoints <= 0) {
    std::cout << "can't attack target: ClapTrap has been destroyed"
              << std::endl;
  } else if (this->m_energyPoints <= 0) {
    std::cout << "can't attack target: no energy to attack!" << std::endl;
  } else {
    std::cout << "ClapTrap attacks " << target << "for " << this->m_attackDmg
              << " damage!" << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {}

void ClapTrap::beRepaired(unsigned int amount) {}

std::string ClapTrap::getName(void) const { return (this->m_name); }
unsigned int ClapTrap::getHitPoints(void) const { return (this->m_hitPoints); }
unsigned int ClapTrap::getEnergyPoints(void) const {
  return (this->m_energyPoints);
}
unsigned int ClapTrap::getAttackDmg(void) const { return (this->m_attackDmg); }