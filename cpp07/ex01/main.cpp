
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 21:51:43 by abhi              #+#    #+#             */
/*   Updated: 2025-08-10 21:51:43 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void capitaliseString(std::string &str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); i++)
		*i = std::toupper(*i);
}

template <typename T>
void timesTwo(T &n)
{
	n *= 2;
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

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	std::cout << "Test 1: int array" << std::endl;
	std::cout << "before: ";
	printArray(arr, 6);
	iter(arr, 6, timesTwo<int>);
	std::cout << "after: ";
	printArray(arr, 6);
	std::cout << std::endl;

	std::cout << "Test 2: string obj array" << std::endl;
	std::string sentence[] = {"hello", "world", "!"};
	std::cout << "before: ";
	printArray(sentence, 3);
	iter(sentence, 3, capitaliseString);
	std::cout << "after: ";
	printArray(sentence, 3);
	return (0);
}
