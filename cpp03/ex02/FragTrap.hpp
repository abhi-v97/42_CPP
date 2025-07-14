/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-14 14:04:25 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-14 14:04:25 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &obj);
	~FragTrap();
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	FragTrap &operator=(FragTrap &obj);
	void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
