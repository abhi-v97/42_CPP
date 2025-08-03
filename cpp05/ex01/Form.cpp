/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-03 20:14:48 by abhi              #+#    #+#             */
/*   Updated: 2025-08-03 20:14:48 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: m_signed(false), m_name("Form"), m_signGrade(Bureaucrat::m_minGrade),
	  m_signExecute(Bureaucrat::m_minGrade)
{
}

Form::Form(const Form &src)
	: m_signed(src.m_signed), m_name(src.m_name), m_signGrade(src.m_signGrade),
	  m_signExecute(src.m_signExecute)
{
}

Form::Form(std::string const &name, int const signGrade, int const executeGrade)
	: m_signed(false), m_name(name), m_signGrade(signGrade), m_signExecute(executeGrade)
{
	if (signGrade < Bureaucrat::m_maxGrade || executeGrade < Bureaucrat::m_maxGrade)
		throw(Form::GradeTooHighException());
	if (signGrade > Bureaucrat::m_minGrade || executeGrade > Bureaucrat::m_minGrade)
		throw(Form::GradeTooLowException());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->m_signed = rhs.m_signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	std::cout << std::ostream::boolalpha;
	o << "Form name: " << i.getName() << "; " << "Sign: " << i.isSigned() << "; "
	  << "Grade to sign: " << i.getSignGrade() << "; "
	  << "Grade to execute: " << i.getExecuteGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::beSigned(Bureaucrat const &b)
{
	if (this->m_signed)
		throw(Form::IsSignedException());
	else if (b.getGrade() > this->m_signGrade)
		throw(Form::GradeTooLowException());
	this->m_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("grade value is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("grade value is too low");
}

const char	*Form::IsSignedException::what() const throw()
{
	return ("Form is already signed.");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &Form::getName() const
{
	return (this->m_name);
}

bool	Form::isSigned() const
{
	return (this->m_signed);
}

int	Form::getSignGrade() const
{
	return (this->m_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (this->m_signExecute);
}

/* ************************************************************************** */