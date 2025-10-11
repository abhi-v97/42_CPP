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
	Array<int> intArray(10);

	std::cout << "TEST: basic int array" << std::endl;
	for (int i = 0; i < 10; i++)
		intArray[i] = i;
	std::cout << "intArray: " << intArray << std::endl;
	std::cout << std::endl;
	
	std::cout << "TEST: empty array creation" << std::endl;
	Array<std::string> emptyArray;
	std::cout << "emptyArray: " << emptyArray << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: assigment operator overload" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "hello";
	strArray[1] = "world";
	strArray[2] = "!";
	emptyArray = strArray;
	std::cout << "emptyArray: " << emptyArray << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: both vars after assignment" << std::endl;
	emptyArray[0] = "something";
	emptyArray[1] = "different";
	std::cout << "emptyArray: " << emptyArray << std::endl;
	std::cout << "strArray: " << strArray << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: copy constructor" << std::endl;
	Array<std::string> copyArray(strArray);
	std::cout << "copyArray: " << copyArray << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: [] operator" << std::endl;
	copyArray[1] = "WORLD";
	std::cout << "copyArray[1]: " << copyArray[1] << std::endl;
	std::cout << "strArray[1]: " << strArray[1] << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: exception" << std::endl;
	try
	{
		copyArray[42];
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;	
	}
	std::cout << std::endl;

	std::cout << "TEST: size method" << std::endl;
	Array<float> floatArray(24);	
	std::cout << "floatArray size: " << floatArray.size() << std::endl;
	
	return (0);
}

