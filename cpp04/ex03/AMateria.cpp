/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 14:31:00 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 14:31:00 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : m_type("undefined")
{
}

AMateria::AMateria(AMateria const & obj)
{
	*this = obj;
}

AMateria::AMateria(std::string const & type) : m_type(type)
{
	
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & obj)
{
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

void AMateria::use(ICharacter & target)
{
	(void) target;
}

std::string const &AMateria::getType() const
{
	return (this->m_type);
}
