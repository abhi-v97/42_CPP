#pragma once

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>

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
		return (pairSize / 2);

	bool oddPair = units % 2 == 1;

	printPairs(pairSize * 2);
	std::cout << "-----" << std::endl;

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


/**
	returns true if an element is part of the main chain (comapred)
*/
bool isMainChain(int i, int pairSize, int size)
{
	// int pairNum = i / pairSize;

	// if ((pairNum + 1) * pairSize > size)
	if (i + pairSize > size)
		return (false);
	if ((i / pairSize) % 2 == 1)
		return (true);

	return (false);
}

template < typename C>
void printMainChain(int posPend, int pairSize, C mResult)
{
	std::cout << "main: [ ";
	for (int i = pairSize - 1; i < posPend; i += pairSize)
	{
		std::cout << mResult.at(i) << ' ';
	}
	std::cout << "]" << std::endl;
	std::cout << "pend: [ ";
	for (size_t i = posPend; i < mResult.size() - pairSize; i += pairSize)
		std::cout << mResult.at(i + pairSize - 1) << ' ';
	std::cout << "]" << std::endl;
	std::cout << "mResult: [ ";
	for (size_t i = 0; i < mResult.size(); i++)
		std::cout << mResult.at(i) << ' ';
	std::cout << "]" << std::endl;
}

/**
	generates insertion order based on Jacobsthal sequence.

	For each Jacobsthal number between 0 and numPend, insert the number and all
	numbers between it and the previous Jacobsthal number.
	
	Skip over a number if it already exists.
	
	Any remaining indices greater than the last Jacobsthal number or not
	included yet go last.
	
	eg: 1, 3, 2, 5, 4, 10, 9, 8, 7, 6...
*/
template < typename Container >
Container PmergeMe<Container>::insertOrder(int numPend, Container jacobSeq)
{
	Container order = Container();
	
	if (numPend <= 0 || jacobSeq.empty())
		return (order);
	
	int prev = 0;
	for (typename Container::const_iterator it = jacobSeq.begin(); it != jacobSeq.end(); it++)
	{
		int i = *it;
		if (i > 0 && i <= numPend)
		{
			order.push_back(i);
			for (int j = i - 1; j > prev; j--)
				order.push_back(j);
			prev = i;
		}
	}
	
	Container expanded;
	for (typename Container::const_iterator it = order.begin(); it != order.end(); it++)
	{
		int j = *it;
		expanded.push_back(j);
		
	}

	for (int i = numPend; i > 1; i--)
	{
		if (std::find(order.begin(), order.end(), i) == order.end())
			order.push_back(i);
	}
	
	// for (size_t i = 0; i < order.size(); i++)
	// 	std::cout << order.at(i) << std::endl;
	
	return (order);
}

template < typename Container >
void PmergeMe< Container >::insert(int pairSize, int numPairs, int numPend, std::vector<int> jacobSeq)
{
	int posPend;
	size_t contSize = mContainer.size();
	Container mResult, mPend;
	
	std::cout << "PairSize: " << pairSize << ", numPairs: " << numPairs << ", numPend: " << numPend << std::endl;
	mResult.reserve(contSize);
	mPend.reserve(contSize);
	for (size_t i = 0; i < contSize; i++)
	{
		if (isMainChain(i, pairSize, contSize))
		{
			mResult.push_back(mContainer.at(i));
		}
		else
		{
			mPend.push_back(mContainer.at(i));
		}
	}
	posPend = mResult.size();
	std::cout << "posPend: " << posPend << std::endl;
	mResult.insert(mResult.end(), mPend.begin(), mPend.end());
	printMainChain(posPend, pairSize, mResult);
	std::cout << "-----" << std::endl;
	mContainer = mResult;

	Container insertOrder = this->insertOrder(9, jacobSeq);
	;
}

template < typename C >
void PmergeMe< C >::sort()
{
	std::cout << "Pair Comparison Stage" << std::endl;
	int pairSize = pairCompare();
	
	std::cout << "-----" << std::endl;
	std::cout << "Insertion Stage" << std::endl;
	std::cout << "-----" << std::endl;
	int maxPend = mContainer.size() / 2 + 1;
	Container jacobSeq = Container();

	for (int i = 2; i < maxPend; i++)
	{
		jacobSeq.push_back(getJacobsthal(i));
		// std::cout << jacobSeq[i] << std::endl;
	}
	
	// if (jacobSeq.size() > 2)
	// {
	// 	typename Container::iterator it = jacobSeq.begin();
	// 	jacobSeq.erase(++it);
	// }

	while (pairSize > 0)
	{
		int numPairs = mContainer.size() / pairSize;
		int numPend = numPairs / 2 + (numPairs % 2 == 1);
		(void) numPend;
		if (numPend > 1)
			insert(pairSize, numPairs, numPend, jacobSeq);
		pairSize /= 2;
	}
	printData("After:\t");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
