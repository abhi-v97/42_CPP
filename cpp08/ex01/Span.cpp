/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:08:50 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/11 16:11:15 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span( const Span & src )
{
	(void) src;
}

Span::Span(int n) : m_maxN(n)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

void Span::addNumber(int n)
{
	this->vect.push_back(n);
	if ((int)this->vect.size() < this->m_maxN)
		;
}

int Span::shortestSpan()
{
	int span = std::abs(this->vect[0] - this->vect[1]);

	for (size_t i = 0; i < this->vect.size() - 1; i++)
	{
		if (std::abs(this->vect[i] - this->vect[i + 1]) < span)
			span = std::abs(this->vect[i] - this->vect[i + 1]);
	}
	return (span);
}

int Span::longestSpan()
{
	int span = std::abs(this->vect[0] - this->vect[1]);

	for (size_t i = 0; i < this->vect.size() - 1; i++)
	{
		if (std::abs(this->vect[i] - this->vect[i + 1]) > span)
			span = std::abs(this->vect[i] - this->vect[i + 1]);
	}
	return (span);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	(void) rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	(void) o;
	(void) i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */