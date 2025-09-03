/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:04:43 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/09 19:34:05 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	(void) src;
}

/*
** -------------------------------- DESTRUCTOR --sssssssssssssssssssssssssssssssssssssssss-----------------------------
*/

Serializer::~Serializer()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void) rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &outf, Data const &obj)
{
	outf << "Data struct address:\t" << &obj << std::endl;
	outf << "int x:\t" << obj.x << std::endl;
	outf << "int y:\t" << obj.y << std::endl;
	return outf;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */