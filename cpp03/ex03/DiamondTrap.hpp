/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 07:24:24 by abhi              #+#    #+#             */
/*   Updated: 2025-07-15 07:24:24 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		static int const defaultHP = FragTrap::defaultHP;
		static int const defaultEnergy = ScavTrap::defaultEnergy;
		static int const defaultDmg = FragTrap::defaultDmg;
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &obj);
		virtual ~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &obj);
		void whoAmI(void);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;

	private:
		std::string m_name;
};

#endif // DIAMONDTRAP_HPP
