#pragma once

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <vector>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template < typename C >
PmergeMe< C >::PmergeMe()
{
	mComp = 0;
}

template < typename C >
PmergeMe< C >::PmergeMe(const PmergeMe &src)
{
	(void)src;
	mComp = 0;
}

template < typename C >
PmergeMe< C >::PmergeMe(const std::string &str)
{
	std::stringstream ss(str);
	std::string buffer;

	for (; std::getline(ss, buffer, ' ');)
	{
		mContainer.push_back(std::atoi(buffer.c_str()));
	}
	mComp = 0;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template < typename C >
PmergeMe< C >::~PmergeMe()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template < typename C >
PmergeMe< C > &PmergeMe< C >::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

template < typename C >
std::ostream &operator<<(std::ostream &o, PmergeMe< C > const &i)
{
	(void)o, (void)i;
	// o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template < typename C >
void PmergeMe< C >::printData(const std::string &msg)
{
	std::cout << msg;
	for (size_t i = 0; i < mContainer.size(); i++)
		std::cout << mContainer.at(i) << ' ';
	std::cout << std::endl;
}

template < typename C >
int PmergeMe< C >::getJacobsthal(int n)
{
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

template < typename C >
void PmergeMe< C >::printPairs(size_t orderNum)
{
	std::cout << "Pairs: { ";
	for (size_t i = 0; i < mContainer.size(); i++)
	{
		std::cout << mContainer.at(i) << ' ';
		if ((i + 1) % orderNum == 0)
			std::cout << "} { ";
	}
	std::cout << std::endl;
}

template < typename C >
int PmergeMe< C >::pairCompare()
{
	static size_t pairSize = 1;

	int units = mContainer.size() / pairSize;

	if (units < 2)
		return (pairSize - 1);

	bool oddPair = units % 2 == 1;

	printPairs(pairSize * 2);

	iterator begin = mContainer.begin();
	iterator end = mContainer.begin() + ((pairSize * units) - (pairSize * oddPair));
	for (iterator it = begin; it < end; it += (pairSize * 2))
	{
		std::cout << "Comparing: " << *(it + pairSize - 1) << " > " << *(it + pairSize * 2 - 1)
				  << std::endl;
		mComp++;
		if (*(it + pairSize - 1) > *(it + pairSize * 2 - 1))
		{
			// for (size_t i = 0; i < orderNum; i++)
			// 	std::swap(*(it + i), *(it + i + orderNum));
			std::cout << "Swapping: " << *it << " and " << *(it + pairSize) << std::endl;
			std::swap_ranges(it, it + pairSize, it + pairSize);
		}
	}

	std::cout << "Recursion Depth: " << pairSize << std::endl;

	pairSize *= 2;

	return (pairCompare());
}

template < typename C >
void PmergeMe< C >::sort()
{
	int recDepth = pairCompare();
	int maxPend = mContainer.size() / 2 + 1;
	std::vector< int > jacobSeq = std::vector<int>(maxPend);

	for (int i = 1; i < maxPend; i++)
	{
		jacobSeq[i] = getJacobsthal(i);
		std::cout << jacobSeq[i] << std::endl;
	}

	std::cout << "recdepth: " << recDepth << std::endl;
	


	printData("After:");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
