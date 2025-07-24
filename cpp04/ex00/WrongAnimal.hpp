/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 19:00:32 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 19:00:32 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string m_type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &obj);
		WrongAnimal(std::string const &type);
		virtual ~WrongAnimal();
		
		WrongAnimal &operator=(WrongAnimal const &obj);
		
		std::string	const &getType() const;
		void				makeSound() const;
		void setType(const std::string &type_);
		
};



#endif // WRONGANIMAL_HPP
