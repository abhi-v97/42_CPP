/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhi <abhi@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 20:08:55 by abhi              #+#    #+#             */
/*   Updated: 2025-07-22 20:08:55 by abhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called " << std::endl;
}

Brain &Brain::operator=(Brain const &obj)
{
	std::cout << "Brain operator overload called." << std::endl;
	if (this != &obj)
		for (int i = 0; i < this->nb_ideas; i++)
			this->m_ideas[i] = obj.m_ideas[i];
	return (*this);
}

std::string Brain::getIdeas(int index) const
{
	if (index < 0)
		index = 0;
	return (this->m_ideas[index % (nb_ideas - 1)]);
}

void Brain::setIdeas(int index, const std::string &idea)
{
	if (index < 0)
		return;
	this->m_ideas[index % (nb_ideas - 1)] = idea;
}
