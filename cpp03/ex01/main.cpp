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
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	ct1("Clappy");
	ClapTrap	ct2("Trappy");

	ct1.attack("Trappy");
	ct2.takeDamage(5);
	ct2.beRepaired(10);
	std::cout << std::endl;

	ct2.attack("Clappy");
	ct1.takeDamage(3);
	ct1.beRepaired(10);
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		ct1.attack("Trappy");
	std::cout << std::endl;
	
	ct2.attack("Trappy");
	ct1.takeDamage(9999);
	ct1.beRepaired(10);
	return (0);
}
