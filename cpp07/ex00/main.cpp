/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:56:28 by abhi              #+#    #+#             */
/*   Updated: 2025/10/17 12:22:27 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <iostream>
#include "template.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << std::endl;
	
	float e = 2.4;
	float f = 4.2;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << min<float>(e, f) << std::endl;
	std::cout << "max( e, f ) = " << max<float>(e, f) << std::endl;
	std::cout << std::endl;

	int g = 0;
	int h = 1;
	int *i = &g;
	int *j = &h;
	::swap(i, j);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "*i = " << *i << ", *j = " << *j << std::endl;
	std::cout << "min( g, h ) = " << min<int>(g, h) << std::endl;
	std::cout << "max( g, h ) = " << max<int>(g, h) << std::endl;

	return (0);
}
