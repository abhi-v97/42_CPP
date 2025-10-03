/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 21:44:58 by abhi              #+#    #+#             */
/*   Updated: 2025-08-10 21:44:58 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <cstdlib>
#include <iostream>

template <typename A, typename F>
void iter(A *array, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void printArray(T *array, size_t len)
{
	std::cout << "{ ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << array[i];
		if (i < len - 1)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}

template <typename T>
void timesTwo(T &n)
{
	n *= 2;
}

#endif // ITER_HPP
