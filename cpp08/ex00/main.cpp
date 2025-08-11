/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:50 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/11 14:52:37 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> array (5, 12);
	
	array.push_back(3);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	array.push_back(7);
	std::cout << easyFind(array, 12) << std::endl;
	return (0);
}
