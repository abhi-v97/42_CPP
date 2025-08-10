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
#include <cstdint>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
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
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<(std::ostream &outf, Data const &obj)
{
	outf << "Data struct address: " << &obj << std::endl;
	outf << "int x: " << obj.x << std::endl;
	outf << "int y: " << obj.y << std::endl;
	return outf;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */