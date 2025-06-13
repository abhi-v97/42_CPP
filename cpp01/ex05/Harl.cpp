/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-12 15:39:58 by avalsang          #+#    #+#             */
/*   Updated: 2025-06-12 15:39:58 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <map>

void Harl::debug(void) const
{
	std::cout << "[debug]" << std::endl;
}

void Harl::info(void) const
{
}

void Harl::warning(void) const
{
}

void Harl::error(void) const
{
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*funcPtr) (void) const;
	std::string levels[4] = {"debug", "info", "warning", "error"};
	funcPtr errorLevels[4] =  { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	int i = 0;
	while (level.compare(levels[i]))
	{
		std::cout << "levels don't match\n";
		i++;
	}
	
	(void) errorLevels[i];
	return ;
}
