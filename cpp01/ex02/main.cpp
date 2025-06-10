/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-05 18:52:22 by abhi              #+#    #+#             */
/*   Updated: 2025-06-05 18:52:22 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>

int main(void) {
	std::string 	string = "HI THIS IS BRAIN";
	std::string 	*stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "&string:\t" << &string << std::endl;
	std::cout << "&stringPTR:\t" << &stringPTR << std::endl;
	std::cout << "&stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "string:\t\t" << string << std::endl;
	std::cout << "*stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "stringREF:\t" << stringREF << std::endl;
	
	return (0);
}
