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

#include <string>

class ClapTrap {
private:
  std::string m_name;
  int m_hitPoints;
  int m_energyPoints;
  int m_attackDmg;

public:
  ClapTrap(void);
  ClapTrap(std::string name);
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDmg(void) const;
};
