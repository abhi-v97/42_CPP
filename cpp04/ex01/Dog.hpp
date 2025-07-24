/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 15:08:35 by abhi              #+#    #+#             */
/*   Updated: 2025-07-18 15:08:35 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &obj);
		~Dog();

		Dog &operator=(Dog const &obj);

		void makeSound() const;

		Brain *getBrain() const;

	private:
		Brain *m_brain;
};

#endif // DOG_HPP
