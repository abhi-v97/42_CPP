/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-12 15:39:58 by avalsang          #+#    #+#             */
/*   Updated: 2025-06-12 15:39:58 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

void Harl::debug(void) const { std::cout << "[debug]" << std::endl; }

void Harl::info(void) const { std::cout << "[info]" << std::endl; }

void Harl::warning(void) const { std::cout << "[warning]" << std::endl; }

void Harl::error(void) const { std::cout << "[error]" << std::endl; }

void Harl::complain(std::string level) {
  typedef void (Harl::*funcPtr)(void) const;
  std::string levels[4] = {"debug", "info", "warning", "error"};
  funcPtr errorLevel[4] = {&Harl::debug, &Harl::info, &Harl::warning,
                           &Harl::error};

  for (int i = 0; i < 4; i++)
    if (level == levels[i])
      return (this->*errorLevel[i])();

  std::cout << "Error: I don't know what " << level << " is supposed to mean."
            << std::endl;
  return;
}
