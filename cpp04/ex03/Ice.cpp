/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 14:50:57 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 14:50:57 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice() : AMateria("Ice")
{
}

Ice::Ice(Ice const &obj) : AMateria(obj)
{
	*this = obj;
}

Ice::~Ice()
{
}

Ice & Ice::operator=(Ice const & obj)
{
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);

}

Ice*Ice::clone() const
{
	return (new Ice(*this));
}


void Ice::use(ICharacter & target)
{
	std::cout << " * Ice shot by " << target.getName() << " *" << std::endl;
}
