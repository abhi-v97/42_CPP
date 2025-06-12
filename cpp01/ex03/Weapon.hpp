/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:28:46 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:28:46 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
  std::string m_type;

public:
  Weapon() {};
  Weapon(std::string type) :m_type(type) {};
  ~Weapon() {};

  std::string getType() const { return m_type; }
  void setType(const std::string &type_) { m_type = type_; }
};

#endif // WEAPON_HPP
