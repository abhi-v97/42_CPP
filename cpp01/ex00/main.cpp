/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 18:52:22 by abhi              #+#    #+#             */
/*   Updated: 2025-06-05 18:52:22 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
	// heap
	Zombie *newZombie1 = newZombie("newZombie1");
	Zombie *newZombie2 = newZombie("newZombie2");
	Zombie *newZombie3 = newZombie("newZombie3");
	std::cout << std::endl;

	// stack
	randomChump("Chump1");
	randomChump("Chump2");
	randomChump("Chump3");
	std::cout << std::endl;

	delete newZombie1;
	delete newZombie2;
	delete newZombie3;
}
