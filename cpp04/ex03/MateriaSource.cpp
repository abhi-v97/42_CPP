/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 16:34:31 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 16:34:31 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < this->m_invSize; i++)
		this->m_inv[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	for (int i = 0; i < this->m_invSize; i++)
		this->m_inv[i] = NULL;
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->m_invSize; i++)
		if (this->m_inv[i])
		{
			delete this->m_inv[i];
		}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < this->m_invSize; i++)
		{
			if (this->m_inv[i])
				delete this->m_inv[i];
			if (obj.m_inv[i])
				this->m_inv[i] = obj.m_inv[i]->clone();
			else
				this->m_inv[i] = NULL;
		}
	}
	return (*this);
}

// free the Materia if inventory is full
void MateriaSource::learnMateria(AMateria *mat)
{
	for (int i = 0; i < m_invSize; i++)
	{
		if (!this->m_inv[i])
		{
			std::cout << "Materia learned: " << mat->getType() << std::endl;
			this->m_inv[i] = mat;
			return;
		}
	}
	std::cout << "No space left in inventory, dropping materia on the floor" << std::endl;
	delete mat;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < m_invSize; i++)
		if (this->m_inv[i] && this->m_inv[i]->getType() == type)
			return (this->m_inv[i]->clone());
	std::cout << "Materia not learned" << std::endl;
	return NULL;
}
