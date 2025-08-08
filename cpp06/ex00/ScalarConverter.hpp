/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-07 21:10:51 by abhi              #+#    #+#             */
/*   Updated: 2025-08-07 21:10:51 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{
	public:
		static void convert(std::string const &str);

	protected:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );
		

	private:
		static void printInt(double d);
		static void printChar(double d);
		static void printFloat(double d);
		static void printDouble(double d);

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */