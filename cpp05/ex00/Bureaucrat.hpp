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
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(int grade);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void	upgrade(Bureaucrat const &src);
		void	downgrade(Bureaucrat const &src);
		Bureaucrat &		operator=( Bureaucrat const & rhs );

	private:

		std::string 		m_name;
		int					m_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
