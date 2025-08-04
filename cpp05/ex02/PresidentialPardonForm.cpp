/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-04 17:00:40 by abhi              #+#    #+#             */
/*   Updated: 2025-08-04 17:00:40 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", PresidentialPardonForm::signGrade,
			PresidentialPardonForm::execGrade),
	  m_target("Null")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), m_target(src.m_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("Presidential Pardon Form", PresidentialPardonForm::signGrade,
			PresidentialPardonForm::execGrade),
	  m_target(target)
{
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->m_target = rhs.m_target;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::executeTarget() const
{
	std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &PresidentialPardonForm::getTarget() const
{
	return (this->m_target);
}

/* ************************************************************************** */