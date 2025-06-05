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
#include <string>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
	Zombie *newZombie1 = newZombie("newZombie1");
	Zombie *newZombie2 = newZombie("newZombie2");
	Zombie *newZombie3 = newZombie("newZombie3");

	randomChump("Chump1");
	randomChump("Chump2");
	randomChump("Chump3");
	
	newZombie1->announce();
	delete newZombie1;
	newZombie2->announce();
	delete newZombie2;
	newZombie3->announce();
	delete newZombie3;
}
