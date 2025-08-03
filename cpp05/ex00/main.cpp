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
#include <exception>
#include <iostream>

void testBureaucrat(std::string const &name, int grade)
{
	std::cout << "Attempting to create a Bureaucrat object named " << name << " with grade "
			  << grade << "." << std::endl;
	try
	{
		Bureaucrat bc(name, grade);
		std::cout << "Success! " << bc << " has been created." << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "** Testing object creation **" << std::endl;
	testBureaucrat("testBelowMin", 160);
	testBureaucrat("testAboveMax", 0);
	testBureaucrat("negativeTest", -123);
	testBureaucrat("MaxGrade", 1);
	testBureaucrat("MinGrade", 150);
	std::cout << std::endl;

	std::cout << "** test operator overload **" << std::endl;
	Bureaucrat test1("test1", 42);
	Bureaucrat test2 = test1;
	std::cout << "Testing overload: " << test2.getName() << ", grade " << test2.getGrade()
			  << std::endl;
	std::cout << std::endl;

	std::cout << "** test copy assignment **" << std::endl;
	test2.gradeUp();
	Bureaucrat test3(test2);
	std::cout << "Testing copy assignment: " << test3.getName() << ", grade "
			  << test3.getGrade() << std::endl;
	std::cout << std::endl;

	std::cout << "** test member func gradeUp **" << std::endl;
	try
	{
		Bureaucrat goodTest("goodTest", 2);
		Bureaucrat badTest("badTest", 1);
		goodTest.gradeUp();
		std::cout << "goodTest gradeUp executed" << std::endl;
		badTest.gradeUp();
		std::cout << "badTest gradeUp executed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** test member func gradeDown **" << std::endl;
	try
	{
		Bureaucrat goodTest("goodTest", 149);
		Bureaucrat badTest("badTest", 150);
		goodTest.gradeDown();
		std::cout << "goodTest gradeDown executed" << std::endl;
		badTest.gradeDown();
		std::cout << "badTest gradeDown executed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}