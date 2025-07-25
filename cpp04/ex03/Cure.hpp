/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 13:08:16 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 13:08:16 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &obj);
		~Cure();
		
		Cure &operator=(Cure const &obj);
		Cure *clone() const;
		void use(ICharacter &obj);
};

#endif // CURE_HPP
