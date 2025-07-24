/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-18 15:01:54 by abhi              #+#    #+#             */
/*   Updated: 2025-07-18 15:01:54 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string m_type;

	public:
		AAnimal();
		AAnimal(std::string &name);
		AAnimal(AAnimal const &obj);
		virtual ~AAnimal();
		
		AAnimal &operator=(AAnimal const &obj);

		virtual void makeSound() const = 0;

		std::string const &getType() const;
		void setType(const std::string &type_);
};

#endif // AANIMAL_HPP
