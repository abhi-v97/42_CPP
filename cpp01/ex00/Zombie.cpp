/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 18:39:10 by abhi              #+#    #+#             */
/*   Updated: 2025-06-05 18:39:10 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
  std::cout << "A zombie appeared!" << std::endl;
  return;
}

Zombie::Zombie(std::string name) : name(name) {
  std::cout << "A zombie named " << this->getName() << " appeared!"
            << std::endl;
  return;
}

Zombie::~Zombie(void) {
  std::cout << "A zombie named " << this->getName() << " has been destroyed!"
            << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
  return;
}

std::string Zombie::getName(void) const { return (this->name); }
