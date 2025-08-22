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
#include "Intern.hpp"

void InternDoEverything(std::string formName, std::string target)
{
	std::cout << "Intern creating form: " << formName << std::endl;
	Intern intern = Intern();
	Bureaucrat b = Bureaucrat("barry", 1);
	AForm *form;

	try
	{
		form = intern.makeForm(formName, target);
		b.signForm(*form);
		b.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	// valid tests
	InternDoEverything("shrubbery creation", "ShrubForm");
	InternDoEverything("robotomy request", "RobotForm");
	InternDoEverything("presidential pardon", "PresForm");

	// invalid tests
	InternDoEverything("", "");
	InternDoEverything("asdfjkl", "ShrubForm");
	InternDoEverything("shrubbery request", "ShrubForm");
	InternDoEverything("TODO: add a bad form name here", "ShrubForm");
	return (0);
}
