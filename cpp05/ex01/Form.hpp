#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Form
{

	public:

		Form();
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );
		std::string GradeTooHighException();
		std::string GradeTooLowException();
		void	beSigned(Bureaucrat const &obj) const;

	private:
		bool sign;
		std::string m_name;
		const int signGrade;
		const int signExec;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */