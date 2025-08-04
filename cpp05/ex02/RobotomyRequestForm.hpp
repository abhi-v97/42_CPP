/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-04 16:59:28 by abhi              #+#    #+#             */
/*   Updated: 2025-08-04 16:59:28 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm(std::string const &name);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		
		std::string const &getTarget() const;

	private:
		std::string m_target;
		void	executeTarget() const;
		static int const signGrade = 72;
		static int const execGrade = 45;

};

#endif // ROBOTOMYREQUESTFORM_HPP
