/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:57:41 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/11 16:11:48 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>

int main()
{
	Span sp = Span(5);
	
	std::cout << "TEST: empty span obj" << std::endl;
	Span empty = Span();

	std::cout << "empty: " << empty << std::endl;
	try
	{
		std::cout << "empty shortest span: " << empty.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "empty longest span: " << empty.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST: add number to empty obj" << std::endl;
	try
	{
		empty.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TEST: addNumber method" << std::endl;
	sp.addNumber(6);
	sp.addNumber(1);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "sp: " << sp << std::endl << std::endl;
	
	std::cout << "TEST: shortest and longest span for sp" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::vector<int> test;
	test.push_back(0);
	test.push_back(4);
	test.push_back(5);
	test.push_back(1);

	std::cout << "TEST: addRange method" << std::endl;
	Span sp2 = Span(5);
	sp2.addRange(test.begin(), test.end());
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: copy constructor" << std::endl;
	Span sp3 = Span(sp2);
	sp3.addNumber(42);
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST: insertion operator overload" << std::endl;
	std::cout << "sp2: " << sp2 << std::endl;
	std::cout << "sp3: " << sp3 << std::endl;
	std::cout << std::endl;
	
	std::cout << "TEST: test addRandom" << std::endl;
	Span sp4 = Span(10);
	sp4.addRandom(10);
	std::cout << "sp4: " << sp4 << std::endl;
	std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
	return (0);
}
