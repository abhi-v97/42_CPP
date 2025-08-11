/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:45:03 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/11 14:50:12 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>

template <typename T>
int easyFind(std::vector<T> vect, int i)
{
	if (vect.empty() != true)
	{
		for (size_t j = 0; j < vect.size(); j++)
		{
			if (vect[j] == i)
				return (vect[j]);
		}
	}
	std::cout << "failed to find element in vector" << std::endl;
	return (-1);
}

#endif // EASYFIND_HPP
