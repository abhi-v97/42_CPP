/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-04 17:01:59 by abhi              #+#    #+#             */
/*   Updated: 2025-08-04 17:01:59 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm(std::string const &name);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		
		std::string const &getTarget() const;

	private:
		std::string m_target;
		void	executeTarget() const;
		static int const signGrade = 145;
		static int const execGrade = 137;

};

#endif // SHRUBBERYCREATIONFORM_HPP
