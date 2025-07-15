/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-06 19:25:23 by abhi              #+#    #+#             */
/*   Updated: 2025-07-06 19:25:23 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		static int const defaultHP = 100;
		static int const defaultEnergy = 50;
		static int const defaultDmg = 20;
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &obj);
		~ScavTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ScavTrap &operator=(ScavTrap &obj);
		void guardGate(void);
};

#endif // SCAVTRAP_HPP
