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

#include "Serializer.hpp"

int main()
{
	Data data = {.x = 123, .y = 456};
	uintptr_t ptr = Serializer::serialize(&data);
	Data *deserializePtr = Serializer::deserialize(ptr);

	std::cout << data << std::endl;
	std::cout << "serialize:\t\t" << ptr << std::endl;
	std::cout << "deserialize: \t\t" << deserializePtr << std::endl;
	
	std::cout << std::endl;
	std::cout << data << std::endl;
	return (0);
}
