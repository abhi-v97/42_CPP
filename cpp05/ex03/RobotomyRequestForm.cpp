/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-04 17:00:51 by abhi              #+#    #+#             */
/*   Updated: 2025-08-04 17:00:51 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", RobotomyRequestForm::signGrade,
			RobotomyRequestForm::execGrade),
	  m_target("Null")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), m_target(src.m_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("Robotomy Request Form", RobotomyRequestForm::signGrade,
			RobotomyRequestForm::execGrade),
	  m_target(target)
{
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->m_target = rhs.m_target;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::executeTarget() const
{
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << this->m_target << ": robotomisation succeeded!" << std::endl;
	else
		std::cout << this->m_target << ": robotomisation failed" << std::endl;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &RobotomyRequestForm::getTarget() const
{
	return (this->m_target);
}

/* ************************************************************************** */