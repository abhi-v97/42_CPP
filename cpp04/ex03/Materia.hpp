/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 13:08:16 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 13:08:16 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Materia_HPP
#define Materia_HPP

#include "AMateria.hpp"

class ICharacter;

class Materia : public AMateria
{
	public:
		Materia();
		Materia(const Materia &obj);
		Materia(std::string const &type);
		virtual ~Materia();

		Materia &operator=(Materia const &obj);
		Materia *clone() const;
		void use(ICharacter &obj);
};

#endif // Materia_HPP
