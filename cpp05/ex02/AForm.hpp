/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-03 21:34:18 by abhi              #+#    #+#             */
/*   Updated: 2025-08-03 21:34:18 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class AForm
{

	public:
		AForm();
		AForm(AForm const &src);
		AForm(std::string const &name, int const signGrade, int const executeGrade);
		virtual ~AForm();

		AForm &operator=(AForm const &rhs);
		std::string const &getName(void) const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class IsSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	protected:
		virtual void executeTarget(void) const = 0;

	private:
		bool m_signed;
		std::string m_name;
		const int m_signGrade;
		const int m_execGrade;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif /* ************************************************************ FORM_H */