/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-22 23:04:12 by abhi              #+#    #+#             */
/*   Updated: 2025-08-22 23:04:12 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Intern const &i)
{
	(void)o;
	(void)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static AForm *createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidentPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	typedef AForm *(*FormSelector)(std::string);
	AForm *form;
	const std::string formNames[3] = {"shrubbery creation", "robotomy request",
									  "presidential pardon"};
	FormSelector formPointer[] = {&createShrubbery, &createRobotomy, &createPresidentPardon};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			form = formPointer[i](target);
			return (form);
		}
	}
	std::cout << "Intern failed to create form " << name << std::endl;
	throw Intern::InvalidFormName();
}

const char *Intern::InvalidFormName::what() const throw()
{
	return ("Intern: bad form name");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */