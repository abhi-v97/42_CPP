/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-04 16:59:19 by abhi              #+#    #+#             */
/*   Updated: 2025-08-04 16:59:19 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm(std::string const &name);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		
		std::string const &getTarget() const;

	private:
		std::string m_target;
		void	executeTarget() const;
		static int const signGrade = 25;
		static int const execGrade = 5;

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */