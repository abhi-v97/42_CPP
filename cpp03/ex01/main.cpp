/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 21:38:35 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 21:38:35 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap	st1("scavvy");
	ScavTrap st2(st1);
	
	std::cout << "st1 attack: " << st1.getAttackDmg() << std::endl;
	std::cout << "st2 attack: " << st2.getAttackDmg() << std::endl;
	st1.setAttackDmg(199);
	std::cout << "st1 attack: " << st1.getAttackDmg() << std::endl;
	std::cout << "st2 attack: " << st2.getAttackDmg() << std::endl;
	return (0);
}
