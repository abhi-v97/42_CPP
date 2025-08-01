/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 14:18:34 by avalsang          #+#    #+#             */
/*   Updated: 2025-08-01 14:18:34 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	this->m_grade = src.m_grade;
	this->m_name = src.m_name;
}

Bureaucrat::Bureaucrat(int grade) : m_name("default"), m_grade(grade)
{
	if (grade < 0 || grade > 150)
		throw 1;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		// this->_value = rhs.getValue();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & src )
{
	o << "Bureaucrat grade " << src.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::upgrade(Bureaucrat const & src)
{
	(void) src;
	this->m_grade++;
	if (this->m_grade < 0 || this->m_grade > 150)
		throw 1;
}


void Bureaucrat::downgrade(Bureaucrat const & src)
{
	(void) src;
	this->m_grade--;
	if (this->m_grade < 0 || this->m_grade > 150)
		throw 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const { return m_name; }
int Bureaucrat::getGrade() const { return m_grade; }

/* ************************************************************************** */