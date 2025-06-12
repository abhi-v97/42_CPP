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
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	(void) argv;
	
	if (argc != 4)
		return (0);
	std::ifstream inf(argv[1]);
	if (!inf)
	{
		std::cerr << "could not open: " << argv[1] << "\n";
		return (1);
	}
	std::string fileName(argv[1]);
	fileName = fileName + ".replace";
	std::ofstream outf(fileName.c_str());	

	std::string str;
	while (std::getline(inf, str))
	{
		if (!str.find(argv[2], 0))
			outf << argv[3] << "\n";
		else
			outf << str << "\n";
	}
	return (0);
}
