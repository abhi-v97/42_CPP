/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:28:23 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:28:23 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
private:
  std::string m_name;
  Weapon &m_weapon;

public:
  HumanA(std::string name_, Weapon &weapon_)
      : m_name(name_), m_weapon(weapon_) {};
  ~HumanA(void) {};
  

  void attack(void) const;

  Weapon getWeapon() const { return m_weapon; }
  void setWeapon(const Weapon &weapon_) { m_weapon = weapon_; }

  std::string getName() const { return m_name; }
  void setName(const std::string &name_) { m_name = name_; }
};

#endif // HUMANA_HPP
