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

MateriaSource::MateriaSource()
{

}

MateriaSource::MateriaSource(MateriaSource const & obj)
{
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *mat)
{
	for (int i = 0; i < m_invSize; i++)
	{
		if (!this->m_inv[i])
			this->m_inv[i] = mat;
	}
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	return nullptr;
}
