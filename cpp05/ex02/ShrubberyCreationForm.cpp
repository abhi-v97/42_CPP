/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-04 17:01:44 by abhi              #+#    #+#             */
/*   Updated: 2025-08-04 17:01:44 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", ShrubberyCreationForm::signGrade,
			ShrubberyCreationForm::execGrade),
	  m_target("Null")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), m_target(src.m_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("Shrubbery Creation Form", ShrubberyCreationForm::signGrade,
			ShrubberyCreationForm::execGrade),
	  m_target(target)
{
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->m_target = rhs.m_target;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::executeTarget() const
{
	std::ofstream out;
	std::string file = this->m_target + "_shrubbery";
	out.open(file.c_str());


	out << " 	   &&& &&  & &&" << std::endl;
	out << "   && &\\/&\\|& ()|/ @, &&" << std::endl;
	out << "   &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	out << "  &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	out << " &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	out << " &&   && & &| &| /& & % ()& /&&" << std::endl;
	out << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	out << "    &&     \\||| " << std::endl;
	out << " 		   |||" << std::endl;
	out << " 		   |||" << std::endl;
	out << " 	 , -=-~  .-^- _" << std::endl;
	out << " ------------------------------" << std::endl;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const &ShrubberyCreationForm::getTarget() const
{
	return (this->m_target);
}

/* ************************************************************************** */