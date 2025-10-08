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

#include <vector>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::vector<int> array;
	
	for (int i = 3; i < 8; i++)
		array.push_back(i);
	std::cout << "Container array: ";
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	easyFind(array, 5);
	try
	{
		easyFind(array, 42);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::deque<int> deque;

	for (int i = 11; i < 16; i++)
		deque.push_back(i);
	std::cout << "Container deque: ";
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	easyFind(deque, 12);
	try
	{
		easyFind(deque, 42);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}

