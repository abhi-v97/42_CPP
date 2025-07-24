/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 20:55:51 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 20:55:51 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
	private:
		std::string m_name;
		static const int m_invSize = 4;	
		AMateria *m_inv[m_invSize];

	public:
		Character();
		Character(std::string &name);
		Character(Character &obj);
		~Character();
		
		Character &operator=(Character const &obj);
	
		std::string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP
