/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-10 22:20:55 by abhi              #+#    #+#             */
/*   Updated: 2025-06-10 22:20:55 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream> 

void HumanB::attack(void) const {
	std::cout << getName() << " attacks with their " << this->m_weapon->getType()
	<< std::endl;
}
