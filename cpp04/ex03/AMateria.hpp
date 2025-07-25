/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 20:52:52 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 20:52:52 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string m_type;

	public:
		AMateria();
		AMateria(AMateria const &obj);
		AMateria(std::string const &type);
		virtual ~AMateria();

		AMateria &operator=(AMateria const &obj);

		std::string const &getType() const;
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);
};

#endif // AMATERIA_HPP
