/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 15:29:10 by avalsang          #+#    #+#             */
/*   Updated: 2025-08-01 15:29:10 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat beau(123);
		std::cout << "outstream test: " << beau << std::endl;
	}
	catch(int)
	{
		std::cerr << "Uh oh" << '\n';
	}
	
}