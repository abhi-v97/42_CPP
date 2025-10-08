/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalsang <avalsang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:08:50 by avalsang          #+#    #+#             */
/*   Updated: 2025/08/11 16:11:15 by avalsang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <cstdlib>
# include <algorithm>
# include <numeric>
# include <vector>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : m_maxN(0), vect()
{
}

Span::Span( Span const & src ) : m_maxN(src.m_maxN), vect(src.vect)
{
}

Span::Span(int n) : m_maxN(n)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if ((int)this->vect.size() == this->m_maxN)
		throw(Span::isFullException());
	this->vect.push_back(n);
}

int Span::shortestSpan()
{
	int result;
	std::vector<int> temp(this->vect);
	std::vector<int> distance(temp);

	if (this->m_maxN < 2)
		throw(Span::invalidSizeException());
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), distance.begin());
	result = *std::min_element(distance.begin() + 1, distance.end());
	return (result);
}

int Span::longestSpan()
{
	int min, max;

	if (this->m_maxN < 2)
		throw(Span::invalidSizeException());
	min = *std::min_element(this->vect.begin(), this->vect.end());
	max = *std::max_element(this->vect.begin(), this->vect.end());
	return (max - min);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span	&Span::operator=( Span const & rhs )
{
	if (this != &rhs)
	{
		this->m_maxN = rhs.m_maxN;
		this->vect.clear();
		this->vect.insert(this->vect.begin(), rhs.vect.begin(),
		    rhs.vect.end());
	}
	return *this;
}

std::ostream	&operator<<( std::ostream &outf, Span const &obj)
{
	outf << "{ ";
	for (size_t i = 0; i < obj.getVect().size(); i++)
		std::cout << obj.getVect().at(i) << " ";
	outf << "}";
	return outf;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Span::isFullException::what() const throw()
{
	return ("Container full, no more space remaining");
}

const char *Span::invalidSizeException::what() const throw()
{
	return ("Container has less than two elements");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int> Span::getVect() const
{
	return (this->vect);
}


/* ************************************************************************** */
