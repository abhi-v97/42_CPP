/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 14:50:57 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 14:50:57 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure() : AMateria("Cure")
{
}

Cure::Cure(Cure const &obj) : AMateria(obj)
{
	*this = obj;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &obj)
{
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

Cure *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << " * heals " << target.getName() << "'s wounds *" << std::endl;
}
