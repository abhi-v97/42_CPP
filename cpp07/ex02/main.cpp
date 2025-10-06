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

	// test copy constructor
	Array<std::string> copyArray(strArray);
	std::cout << "copyArray: " << copyArray << std::endl;

	// test [] operator
	copyArray[1] = "WORLD";
	std::cout << "emptyArray[1]: " << emptyArray[1] << std::endl;
	std::cout << "copyArray[1]: " << copyArray[1] << std::endl;
	std::cout << std::endl;

	// test exception
	try
	{
		copyArray[42];
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}
	std::cout << std::endl;

	// test size method
	Array<float> floatArray(24);	
	std::cout << "floatArray size: " << floatArray.size() << std::endl;
	
	return (0);
}

