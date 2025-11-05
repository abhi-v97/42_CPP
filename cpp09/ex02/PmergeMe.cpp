#pragma once

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>

#ifdef DEBUG
#define DEBUG_PRINT(expr)                                                                          \
	do                                                                                             \
	{                                                                                              \
		(expr);                                                                                    \
	} while (0)
#define DEBUG_BLOCK(code)                                                                          \
	do                                                                                             \
	{                                                                                              \
		code                                                                                       \
	} while (0)
#else
#define DEBUG_PRINT(expr)                                                                          \
	do                                                                                             \
	{                                                                                              \
		(void)0;                                                                                   \
	} while (0)
#define DEBUG_BLOCK(code)                                                                          \
	do                                                                                             \
	{                                                                                              \
		(void)0;                                                                                   \
	} while (0)
#endif

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template < typename C >
PmergeMe< C >::PmergeMe()
{
	mComp = 0;
}

template < typename C >
PmergeMe< C >::PmergeMe(const PmergeMe< C > &src)
{
	this->mContainer = src.mContainer;
}

template < typename C >
PmergeMe< C >::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		mContainer.push_back(std::atoi(argv[i]));
	}
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
	this->mContainer = rhs.mContainer;
	return *this;
}

template < typename C >
std::ostream &operator<<(std::ostream &o, PmergeMe< C > const &i)
{
	o << "This class attempts to sort a list of numbers using the Merge-Insertion Sort Algorithm";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template < typename Container >
void PmergeMe< Container >::sort()
{
	int maxPend = mContainer.size() / 2 + 1;
	Container jacobSeq = Container();
	for (int i = 0; i < maxPend; i++)
	{
		jacobSeq.push_back(getJacobsthal(i));
	}
	if (jacobSeq.size() > 2)
	{
		typename Container::iterator it = jacobSeq.begin();
		jacobSeq.erase(++it);
	}
	DEBUG_PRINT(std::cout << "-----" << std::endl);
	DEBUG_PRINT(std::cout << "Pair Comparison Stage" << std::endl);
	int pairSize = pairCompare();	

	DEBUG_PRINT(std::cout << "-----" << std::endl);
	DEBUG_PRINT(std::cout << "Insertion Stage" << std::endl);
	DEBUG_PRINT(std::cout << "-----" << std::endl);
	while (pairSize > 0)
	{
		int numPairs = mContainer.size() / pairSize;
		int numPend = numPairs / 2 + (numPairs % 2 == 1);
		if (numPend > 1)
			insert(pairSize, numPend, jacobSeq);
		pairSize /= 2;
	}
	printData("After:\t");
	std::cout << "Total Comparisons : " << mComp << std::endl;
}

template < typename C >
int PmergeMe< C >::pairCompare()
{
	static size_t pairSize = 1;

	int units = mContainer.size() / pairSize;
	if (units < 2)
		return (pairSize / 2);
	DEBUG_PRINT(std::cout << "-----" << std::endl);
	DEBUG_PRINT(std::cout << "Pair Size: " << pairSize << std::endl);

	bool oddPair = units % 2 == 1;

	iterator begin = mContainer.begin();
	iterator end = begin;
	std::advance(end, (pairSize * units) - (pairSize * oddPair));

	for (iterator it = begin; it != end;)
	{
		iterator lastA = it;
		iterator lastB = it;
		std::advance(lastA, pairSize - 1);
		std::advance(lastB, pairSize * 2 - 1);

		DEBUG_PRINT(std::cout << "Comparing: " << *lastA << " > " << *lastB << std::endl);
		mComp++;
		if (*lastA > *lastB)
		{
			iterator mid = it;

			DEBUG_PRINT(std::cout << "Swapping: " << *lastA << " and " << *lastB << std::endl);
			std::advance(mid, pairSize);
			std::swap_ranges(it, mid, mid);
		}
		std::advance(it, pairSize * 2);
	}
	DEBUG_PRINT(printPairs(pairSize));
	pairSize *= 2;
	return (pairCompare());
}

template < typename Container >
void PmergeMe< Container >::insert(int pairSize, int numPend, Container &jacobSeq)
{
	int posPend;
	size_t contSize = mContainer.size();
	Container mMain, mPend;

	DEBUG_PRINT(std::cout << "PairSize: " << pairSize << ", numPend: " << numPend << std::endl);
	for (size_t i = 0; i < contSize; i++)
	{
		if (isMainChain(i, pairSize, contSize))
		{
			mMain.push_back(getElement(i));
		}
		else
		{
			mPend.push_back(getElement(i));
		}
	}
	posPend = mMain.size();
	mMain.insert(mMain.end(), mPend.begin(), mPend.end());
	mContainer = mMain;
	DEBUG_PRINT(std::cout << "posPend: " << posPend << std::endl);
	DEBUG_PRINT(printMainChain(posPend, pairSize));
	DEBUG_PRINT(std::cout << "-----" << std::endl);

	Container insertOrder = PmergeMe<Container>::insertOrder(numPend, jacobSeq);

	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		iterator it = insertOrder.begin();
		std::advance(it, i);
		int bX = *it;
		size_t numMoved = countNumMoved(insertOrder, it, bX);

		size_t start = posPend + (bX - 1 - numMoved) * pairSize;
		size_t end = start + pairSize;

		int k = getK(bX, jacobSeq);
		size_t usefulMain = getUsefulMain(k, posPend, pairSize);

		DEBUG_PRINT(std::cout << "Looking at b" << bX << ", value = " << getElement(end - 1) << std::endl);
		DEBUG_PRINT(std::cout << "insertion group k: " << k << std::endl);
		DEBUG_PRINT(std::cout << "last useful chain: " << usefulMain << std::endl);
		size_t insertPos = (bX != 1) ? insertPair(getElement(end - 1), pairSize, usefulMain) : 0;

		if (insertPos < start)
		{
			iterator first = mContainer.begin();
			iterator middle = first;
			iterator last = first;

			std::advance(first, insertPos);
			std::advance(middle, start);
			std::advance(last, end);
			std::rotate(first, middle, last);
		}
		DEBUG_PRINT(printData("container after insertion:\t"));
		DEBUG_PRINT(std::cout << "-----" << std::endl);
		posPend += pairSize;
	}
}

/*
** --------------------------------- HELPERS ---------------------------------
*/

template < typename C >
int PmergeMe< C >::getJacobsthal(int n)
{
	return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

/**
	returns true if an element is part of the main chain (comapred)
*/
bool isMainChain(int i, int pairSize, int size)
{
	if (i + pairSize > size)
		return (false);
	if ((i / pairSize) % 2 == 1)
		return (true);

	return (false);
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
Container PmergeMe< Container >::insertOrder(int numPend, Container &jacobSeq)
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
	for (int i = numPend; i > 1; i--)
	{
		if (std::find(order.begin(), order.end(), i) == order.end())
			order.push_back(i);
	}
	return (order);
}

size_t getUsefulMain(int k, size_t posPend, size_t pairSize)
{
	size_t usefulEnd = (1u << k) - 1;
	size_t availPairs = posPend / pairSize;

	if (usefulEnd > availPairs)
		return (availPairs);
	return (usefulEnd);
}

template < typename Container >
size_t PmergeMe< Container >::insertPair(int value, size_t pairSize, size_t numPairs)
{
	size_t left = 0;
	size_t right = numPairs;

	while (left < right)
	{
		size_t mid = (left + right) / 2;
		int midValue = getElement((pairSize - 1) + mid * pairSize);

		DEBUG_PRINT(std::cout << "Comparing: " << value << " < " << midValue << std::endl);
		mComp++;
		if (value < midValue)
			right = mid;
		else
			left = mid + 1;
	}
	return (left * pairSize);
}

template < typename Container >
int PmergeMe< Container >::getK(int bX, const Container &jacobSeq)
{
	typename Container::const_iterator it = jacobSeq.begin();
	int i = 0;

	for (; it != jacobSeq.end(); it++, i++)
		if (bX <= *it)
			return (i);
	return (i);
}

template < typename Container >
size_t PmergeMe< Container >::countNumMoved(const Container &insertOrder, iterator endIt, int bX)
{
	size_t count = 0;

	for (typename Container::const_iterator it = insertOrder.begin(); it != endIt; it++)
	{
		if (*it < bX)
			count++;
	}
	return (count);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

template < typename Container >
typename Container::reference PmergeMe< Container >::getElement(typename Container::size_type index)
{
	return getElementOverload(
		index, typename std::iterator_traits< typename Container::iterator >::iterator_category());
}

template < typename Container >
typename Container::reference PmergeMe< Container >::getElementOverload(
	typename Container::size_type index, std::random_access_iterator_tag)
{
	if (index >= mContainer.size())
	{
		throw std::out_of_range("Index out of bounds (vector)");
	}
	return mContainer.at(index);
}

template < typename Container >
typename Container::reference PmergeMe< Container >::getElementOverload(
	typename Container::size_type index, std::bidirectional_iterator_tag)
{

	if (index >= mContainer.size())
	{
		throw std::out_of_range("Index out of bounds (list)");
	}
	typename Container::iterator it = mContainer.begin();
	std::advance(it, index);
	return *it;
}

/*
** --------------------------------- DEBUG HELPERS ---------------------------------
*/

template < typename C >
void PmergeMe< C >::printData(const std::string &msg)
{
	std::cout << msg;
	for (size_t i = 0; i < mContainer.size(); i++)
		std::cout << getElement(i) << ' ';
	std::cout << std::endl;
}

template < typename C >
void PmergeMe< C >::printPairs(size_t orderNum)
{
	std::cout << "Pairs after swap: { ";
	for (size_t i = 0; i < mContainer.size(); i++)
	{
		std::cout << getElement(i) << ' ';
		if ((i + 1) % orderNum == 0)
			std::cout << "} { ";
	}
	std::cout << std::endl;
}

template < typename C >
void PmergeMe<C>::printMainChain(int posPend, int pairSize)
{
	std::cout << "main: [ ";
	for (int i = pairSize - 1; i < posPend; i += pairSize)
	{
		std::cout << getElement(i) << ' ';
	}
	std::cout << "]" << std::endl;
	std::cout << "pend: [ ";
	for (size_t i = posPend; i < mContainer.size() - pairSize; i += pairSize)
		std::cout << getElement(i + pairSize - 1) << ' ';
	std::cout << "]" << std::endl;
	std::cout << "mResult: [ ";
	for (size_t i = 0; i < mContainer.size(); i++)
		std::cout << getElement(i) << ' ';
	std::cout << "]" << std::endl;
}

template < typename C >
void PmergeMe< C >::isSorted()
{
	for (size_t i = 1; i < mContainer.size(); i++)
	{
		if (getElement(i) < getElement(i - 1))
		{
			std::cout << "NOT SORTED" << std::endl;
			return;
		}
	}
	std::cout << "SEE IT, SAY IT, SORTED" << std::endl;
}

/* ************************************************************************** */
