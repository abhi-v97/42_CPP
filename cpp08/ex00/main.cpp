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

template<typename Iter>
void printArray(Iter begin, Iter end)
{
	std::cout << "{ ";
	for (; begin != end; begin++)
		std::cout << *begin  << " ";
	std::cout << "}" << std::endl;
}

int main()
{
	std::vector<int> vect;
	
	for (int i = 3; i < 8; i++)
		vect.push_back(i);
	std::cout << "Container array: ";
	printArray(vect.begin(), vect.end());

	std::cout << "Test 1: find valid element in vector container" << std::endl;
	std::cout << "Result: ";
	easyFind(vect, 5);
	std::cout << std::endl;
	
	std::cout << "Test 2: test exception, array out of bounds" << std::endl;
	std::cout << "Result: ";
	try
	{
		easyFind(vect, 42);
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
	printArray(deque.begin(), deque.end());

	std::cout << "Test 3: find valid element in deque container" << std::endl;
	std::cout << "Result: ";
	easyFind(deque, 12);
	std::cout << std::endl;
	return (0);
}
