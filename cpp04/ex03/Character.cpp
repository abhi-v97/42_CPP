#include "Character.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 14:40:55 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 14:40:55 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Character::Character() :m_name("undefined")
{
	for (int i = 0; i < m_invSize; i++)
		this->m_inv[i] = NULL;
}

Character::Character(std::string & name) : m_name(name)
{
	for (int i = 0; i < m_invSize; i++)
		this->m_inv[i] = NULL;
}

Character::Character(Character & obj)
{
	*this = obj;
}

Character::~Character()
{
	for (int i = 0; i < m_invSize; i++)
		if (this->m_inv[i])
			delete this->m_inv[i];
}

Character & Character::operator=(Character const & obj)
{
	if (this != &obj)
	for (int i = 0; i < m_invSize; i++)
	{
		if (this->m_inv[i])
			delete this->m_inv[i];
		if (obj.m_inv[i])
			this->m_inv[i] = obj.m_inv[i];
		else
			this->m_inv[i] = NULL;
	}
	return (*this);
}

void Character::equip(AMateria * m)
{
	for (int i = 0; i < m_invSize; i++)
		if (!this->m_inv[i])
			this->m_inv[i] = m;
}

void Character::unequip(int idx)
{
	this->m_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter & target)
{

}
