/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-22 15:25:32 by abhi              #+#    #+#             */
/*   Updated: 2025-06-22 15:25:32 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected:
  std::string m_name;
  int m_hitPoints;
  int m_energyPoints;
  int m_attackDmg;

public:
  static int const defaultHitPoints = 10;
  static int const defaultEnergyPoints = 10;
  static int const defaultAttackDmg = 0;

  ClapTrap(void);
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const &obj);
  ~ClapTrap(void);

  ClapTrap &operator=(ClapTrap const &obj);
  
  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDmg(void) const;
  
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void setAttackDmg(int attackDmg) { m_attackDmg = attackDmg; }
};

# endif
