/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:14:48 by abhi              #+#    #+#             */
/*   Updated: 2025/08/23 16:50:22 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm()
	: m_signed(false), m_name("Form"), m_signGrade(Bureaucrat::m_minGrade),
	  m_execGrade(Bureaucrat::m_minGrade)
{
}

AForm::AForm(const AForm &src)
	: m_signed(src.m_signed), m_name(src.m_name), m_signGrade(src.m_signGrade),
	  m_execGrade(src.m_execGrade)
{
}

AForm::AForm(std::string const &name, int const signGrade, int const executeGrade)
	: m_signed(false), m_name(name), m_signGrade(signGrade), m_execGrade(executeGrade)
{
	if (signGrade < Bureaucrat::m_maxGrade || executeGrade < Bureaucrat::m_maxGrade)
		throw(AForm::GradeTooHighException());
	if (signGrade > Bureaucrat::m_minGrade || executeGrade > Bureaucrat::m_minGrade)
		throw(AForm::GradeTooLowException());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->m_signed = rhs.m_signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	std::cout << std::boolalpha;
	o << "Form name: " << i.getName() << "; " << "signed: " << i.isSigned() << "; "
	  << "Grade to sign: " << i.getSignGrade() << "; "
	  << "Grade to execute: " << i.getExecuteGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::beSigned(Bureaucrat const &b)
{
	if (this->m_signed)
		throw(AForm::IsSignedException());
	else if (b.getGrade() > this->m_signGrade)
		throw(AForm::GradeTooLowException());
	this->m_signed = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("grade value is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("grade value is too low");
}

const char	*AForm::IsSignedException::what() const throw()
{
	return ("Form is already signed.");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &AForm::getName() const
{
	return (this->m_name);
}

bool	AForm::isSigned() const
{
	return (this->m_signed);
}

int	AForm::getSignGrade() const
{
	return (this->m_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (this->m_execGrade);
}

/* ************************************************************************** */