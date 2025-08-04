/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 14:19:21 by avalsang          #+#    #+#             */
/*   Updated: 2025-08-01 14:19:21 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{

	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void signForm(AForm &form) const;
		void executeForm(AForm &form) const;
		void gradeUp(void);
		void gradeDown(void);
		Bureaucrat &operator=(Bureaucrat const &rhs);

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

		static int const m_maxGrade = 1;
		static int const m_minGrade = 150;

	private:
		std::string m_name;
		int m_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

/* ****************************************************** BUREAUCRAT_H */
#endif
