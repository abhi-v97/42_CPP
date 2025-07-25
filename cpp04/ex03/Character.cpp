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

#include "Character.hpp"
#include <iostream>
#include <string>

Character::Character() : m_name("undefined")
{
	for (int i = 0; i < m_invSize; i++)
		this->m_inv[i] = NULL;
}

Character::Character(const std::string &name) : m_name(name)
{
	for (int i = 0; i < m_invSize; i++)
		this->m_inv[i] = NULL;
}

Character::Character(Character &obj)
{
	*this = obj;
}

Character::~Character()
{
	for (int i = 0; i < m_invSize; i++)
		if (this->m_inv[i])
			delete this->m_inv[i];
}

Character &Character::operator=(Character const &obj)
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

const std::string &Character::getName() const
{
	return (this->m_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Materia doesn't exist! Can't equip it" << std::endl;
		return ;
	}
	for (int i = 0; i < m_invSize; i++)
		if (!this->m_inv[i])
		{
			this->m_inv[i] = m;
			std::cout << this->m_name << " equips " << m->getType() << " in slot " << i
					  << std::endl;
			return;
		}
	std::cout << "Inventory is full, dropping Materia on the floor" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < this->m_invSize && this->m_inv[idx])
	{
		std::cout << this->m_name << " unequips " << this->m_inv[idx]->getType() << std::endl;
		this->m_inv[idx] = NULL;
		return ;
	}
	std::cout << "Cannot unequip item because reasons" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < this->m_invSize && this->m_inv[idx])
		this->m_inv[idx]->use(target);
	else
		std::cout << " * " << this->m_name << " scratches his head in confusion * " << std::endl;
}
