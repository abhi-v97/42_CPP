/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:04:30 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/09 19:26:42 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
		int x;
		int y;
};

class Serializer
{

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &src);
		~Serializer();

		Serializer &operator=(Serializer const &rhs);
};

std::ostream &operator<<(std::ostream &outf, Data const &obj);

#endif /* ****************************************************** SERIALIZER_H */