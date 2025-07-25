/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 14:50:57 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 14:50:57 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"
#include "AMateria.hpp"
#include <iostream>

Materia::Materia() : AMateria("Materia")
{
}

Materia::Materia(Materia const &obj) : AMateria(obj)
{
	*this = obj;
}

Materia::Materia(std::string const &type)
	: AMateria(type)
{
}

Materia::~Materia()
{
}

Materia &Materia::operator=(Materia const &obj)
{
	if (this != &obj)
		this->m_type = obj.m_type;
	return (*this);
}

Materia *Materia::clone() const
{
	return (new Materia(*this));
}

void Materia::use(ICharacter &target)
{
	std::cout << " * used " << this->m_type << " materia on " << target.getName() << " *" << std::endl;
}
