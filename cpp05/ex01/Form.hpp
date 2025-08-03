/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-03 20:10:10 by abhi              #+#    #+#             */
/*   Updated: 2025-08-03 20:10:10 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form
{

	public:
		Form();
		Form(Form const &src);
		Form(std::string const &name, int const signGrade, int const executeGrade);
		~Form();

		Form &operator=(Form const &rhs);
		void beSigned(Bureaucrat const &b);
		std::string const &getName(void) const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

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

	private:
		bool m_signed;
		std::string m_name;
		const int m_signGrade;
		const int m_signExecute;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */