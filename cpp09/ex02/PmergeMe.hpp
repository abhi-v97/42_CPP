#pragma once

#include <ctime>
#include <iostream>
#include <string>

template < typename C >
class PmergeMe
{

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe(const std::string &str);
		PmergeMe(char **argv);

		~PmergeMe();

		PmergeMe &operator=(PmergeMe const &rhs);

		void printData(const std::string &msg);
		void printPairs(size_t orderNum);
		int pairCompare();

		typedef C Container;
		typedef typename C::iterator iterator;
		typename C::iterator begin();
		typename C::iterator end();
		int getJacobsthal(int n);
		void sort();
		void insert(int pairSize, int numPairs, int numPend, Container &jacobSeq);
		Container insertOrder(int numPend, Container jacobSeq);
		void isSorted();

		typename Container::reference getElement(typename Container::size_type index)
		{
			return getElement_impl(
				index,
				typename std::iterator_traits< typename Container::iterator >::iterator_category());
		}

	private:
		time_t mStart;
		time_t mEnd;
		C mContainer;
		double time();
		void sort(C &cont);
		std::string container_type();
		int mComp;

		size_t countNumMoved(const Container &insertOrder, typename Container::const_iterator endIt,
							 int bX);
		int getK(int bX, const Container &jacobSeq);
		size_t insertPair(int value, size_t pairSize, size_t numPairs);

		typename Container::reference getElement_impl(typename Container::size_type index,
													  std::random_access_iterator_tag)
		{
			if (index >= mContainer.size())
			{
				throw std::out_of_range("Index out of bounds (vector-like)");
			}
			return mContainer.at(index); // Or mContainer[index] if you skip bounds checking
		}

		typename Container::reference getElement_impl(typename Container::size_type index,
													  std::bidirectional_iterator_tag)
		{

			if (index >= mContainer.size())
			{
				throw std::out_of_range("Index out of bounds (list-like)");
			}

			typename Container::iterator it = mContainer.begin();
			std::advance(it, index);
			return *it;
		}
};

template < typename C >
std::ostream &operator<<(std::ostream &o, PmergeMe< C > const &i);

#include "PmergeMe.cpp"
