/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 15:01:54 by abhi              #+#    #+#             */
/*   Updated: 2025-07-18 15:01:54 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string m_type;

	public:
		Animal();
		Animal(std::string const &name);
		Animal(Animal const &obj);
		virtual ~Animal();
		
		Animal &operator=(Animal const &obj);

		virtual void makeSound() const;

		std::string const &getType() const;
		void setType(const std::string &type_);
};

#endif // ANIMAL_HPP
