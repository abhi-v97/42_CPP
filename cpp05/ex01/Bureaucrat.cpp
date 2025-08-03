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
#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : m_name("NoName"), m_grade(Bureaucrat::m_minGrade)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : m_name(src.m_name), m_grade(src.m_grade)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : m_name(name), m_grade(grade)
{
	if (grade < Bureaucrat::m_maxGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::m_minGrade)
		throw(Bureaucrat::GradeTooLowException());
	return;
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

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->m_grade = rhs.m_grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << "Name: " << src.getName() << "Grade: " << src.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureaucrat " << this->m_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::gradeUp(void)
{
	if (this->m_grade - 1 < Bureaucrat::m_maxGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	this->m_grade--;
}

void Bureaucrat::gradeDown(void)
{
	if (this->m_grade + 1 > Bureaucrat::m_minGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	this->m_grade++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

/*
** --------------------------------- EXCEPTIONS --------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high, grade cannot go below 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low, grade cannot go above 150";
}

/* ************************************************************************** */
