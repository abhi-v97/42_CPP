/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-10 17:56:28 by abhi              #+#    #+#             */
/*   Updated: 2025-08-10 17:56:28 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << std::endl;
	float e = 2.4;
	float f = 4.2;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << min<float>(e, f) << std::endl;
	std::cout << "max( e, f ) = " << max<float>(e, f) << std::endl;

	std::cout << std::endl;
	std::string g = "abc";
	std::string h = "ABC";
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << min<std::string>(g, h) << std::endl;
	std::cout << "max( g, h ) = " << max<std::string>(g, h) << std::endl;

	return (0);
}
