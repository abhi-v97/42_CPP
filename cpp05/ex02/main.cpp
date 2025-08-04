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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{

	Bureaucrat a = Bureaucrat("Old Guard", 1);
	Bureaucrat b = Bureaucrat("New Hire", 150);

	ShrubberyCreationForm shrubForm = ShrubberyCreationForm("ShrubForm");
	RobotomyRequestForm robotForm = RobotomyRequestForm("RobotForm");
	PresidentialPardonForm pardonForm = PresidentialPardonForm("PardonForm");
	
	std::cout << std::boolalpha;

	std::cout << "** Test new hire attempting to sign forms **" << std::endl;
	b.signForm(shrubForm);
	b.signForm(robotForm);
	b.signForm(pardonForm);
	std::cout << std::endl;

	std::cout << "** Test new hire attempting to execute forms **" << std::endl;
	b.executeForm(shrubForm);
	b.executeForm(robotForm);
	b.executeForm(pardonForm);
	std::cout << std::endl;
	
	std::cout << "** Now attempting with proper authority **" << std::endl;
	a.signForm(shrubForm);
	a.signForm(robotForm);
	a.signForm(pardonForm);
	std::cout << "Shrub form signed: " << shrubForm.isSigned() << std::endl;
	std::cout << "Robot form signed: " << shrubForm.isSigned() << std::endl;
	std::cout << "Pardon form signed: " << shrubForm.isSigned() << std::endl;

	a.executeForm(shrubForm);
	a.executeForm(robotForm);
	a.executeForm(pardonForm);
	std::cout << std::endl;

	return (0);
}
