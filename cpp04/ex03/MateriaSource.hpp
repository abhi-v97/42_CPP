/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-24 13:57:12 by avalsang          #+#    #+#             */
/*   Updated: 2025-07-24 13:57:12 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static const int m_invSize = 4;
		AMateria *m_inv[m_invSize];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &obj);
		virtual ~MateriaSource();

		MateriaSource &operator=(MateriaSource const &obj);

		void learnMateria(AMateria *mat);
		AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP
