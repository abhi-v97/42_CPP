/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 13:08:16 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 13:08:16 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &obj);
		~Ice();

		Ice &operator=(Ice const &obj);
		Ice *clone() const;
		void use(ICharacter &obj);
};

#endif // ICE_HPP
