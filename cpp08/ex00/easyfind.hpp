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

# include <algorithm>
# include <iostream>
# include <stdexcept>

template <typename T>
typename T::iterator easyFind(T &vect, int i)
{
	typename T::iterator j = std::find(vect.begin(), vect.end(), i);
	if (j != vect.end())
	{
		int index = j - vect.begin();
		std::cout << "Element " << vect[index] << " found at pos " << index << std::endl;
		return (j);
	}
	else
	{
		throw (std::out_of_range("Element not found"));
	}
	return (j);
}

#endif // EASYFIND_HPP
