/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:28:32 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:28:32 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
  Weapon *m_weapon;
  std::string m_name;

  public:
  HumanB(std::string name) : m_name(name) {};
  HumanB (void) {};
  ~HumanB(void) {};

  void attack(void) const;

  Weapon getWeapon() const { return *m_weapon; }
  void setWeapon(Weapon &weapon_) { this->m_weapon = &weapon_; }

  std::string getName() const { return m_name; }
  void setName(const std::string &name_) { m_name = name_; }

};

#endif // HUMANB_HPP
