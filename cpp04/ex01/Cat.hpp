/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 18:57:43 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 18:57:43 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &obj);
		virtual ~Cat();

		Cat &operator=(Cat const &obj);

		void makeSound() const;
		Brain *getBrain() const;

	private:
		Brain *m_brain;
};

#endif // CAT_HPP
