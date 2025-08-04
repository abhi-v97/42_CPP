/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 15:29:10 by avalsang          #+#    #+#             */
/*   Updated: 2025-08-01 15:29:10 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <ios>
#include <iostream>

void testForm(std::string const &name, int const signGrade, int const execGrade)
{
	std::cout << "Attempting to create a Form object " << name << " with sign grade " << signGrade
			  << " & exec grade " << execGrade << std::endl;
	try
	{
		AForm form(name, signGrade, execGrade);
		std::cout << "Success! Form created successfully." << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "** Testing object creation **" << std::endl;
	testForm("LargeSignGrade", 1200, 12);
	testForm("LargeExecGrade", 1, 1234);
	testForm("SmallSignGrade", 0, 12);
	testForm("SmallExecGrade", 1, 0);
	std::cout << std::endl;

	std::cout << "** Test signForm() from class Bureaucrat **" << std::endl;
	try
	{
		Bureaucrat a("name", 12);

		AForm form("form", 24, 1);
		a.signForm(form);
		std::cout << "Success!." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "** test signForm() when form is already signed **" << std::endl;
		Bureaucrat a("name", 12);
		AForm form("form", 24, 1);
	
		a.signForm(form);
		std::cout << std::boolalpha;
		std::cout << "Form sign: " << form.isSigned() << std::endl;
		a.signForm(form);
		std::cout << std::endl;
	}
	{
		std::cout << "** test beSigned() member function **" << std::endl;
		Bureaucrat a("name", 42);
		AForm form("form", 24, 1);
	
		a.signForm(form);
		std::cout << std::endl;
	}

	return (0);
}
