/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-11 09:37:48 by abhi              #+#    #+#             */
/*   Updated: 2025-08-11 09:37:48 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> array(10);
	for (int i = 0; i < 10; i++)
		array[i] = 0 + i;

	std::cout << array[2] << std::endl;
	std::cout << array[3] << std::endl;
	std::cout << array[4] << std::endl;
	
	// test empty array creation
	Array<std::string> emptyArray;
	std::cout << "emptyArray: " << emptyArray << std::endl;

	// test assigment operator overload
	Array<std::string> strArray(3);
	strArray[0] = "hello";
	strArray[1] = "world";
	strArray[2] = "!";
	emptyArray = strArray;
	std::cout << "emptyArray: " << emptyArray << std::endl;
}
