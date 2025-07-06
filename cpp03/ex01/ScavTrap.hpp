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

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &obj);
	~ScavTrap();
	
	ScavTrap &operator=(ScavTrap &obj);
	void guardGate(void);

};