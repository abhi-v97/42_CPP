
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

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	std::cout << "before: ";
	printArray(arr, 6);
	iter(arr, 6, timesTwo<int>);
	std::cout << "after: ";
	printArray(arr, 6);

	std::string sentence[] = {"hello", "world", "!"};
	std::cout << "before: ";
	printArray(sentence, 3);
	iter(sentence, 3, capitaliseString);
	std::cout << "after: ";
	printArray(sentence, 3);
	return (0);
}
