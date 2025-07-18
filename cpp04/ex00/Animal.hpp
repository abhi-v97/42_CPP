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

#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string name);
		~Animal();

		void makeSound();

		std::string getType() const;
		void setType(const std::string &type_);
};