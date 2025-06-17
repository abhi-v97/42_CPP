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
#include <cstdlib>

int main(int argc, char **argv) {
	Zombie			*horde;
	int				n = 3;
	std::string		name = "zombie";

	if (argc != 1 && atoi(argv[1]) >= 0)
	 	n = atoi(argv[1]);
	if (argc >= 3)
		name = argv[2];

	horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}
