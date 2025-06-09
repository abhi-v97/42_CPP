/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-26 15:05:05 by abhi              #+#    #+#             */
/*   Updated: 2025-05-26 15:05:05 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h> // for toupper

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::cout << "\e[1;93m";
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
		}
		std::cout << "\e[0m" << std::endl;
	}
	else
		std::cout << "\e[1;93m" << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\e[0m" << std::endl;
	return (0);
}
