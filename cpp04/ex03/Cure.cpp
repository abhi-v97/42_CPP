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

Cure::Cure()
{
}

Cure::Cure(Cure const & obj)
{
	*this = obj;
}

Cure::~Cure()
{
}

Cure & Cure::operator=(Cure const & obj)
{
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

void Cure::use(ICharacter & target)
{
	(void) target;
}
