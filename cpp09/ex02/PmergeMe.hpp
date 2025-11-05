#pragma once

#include <ctime>
#include <iostream>
#include <string>

template < typename Container >
class PmergeMe
{

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe(const std::string &str);
		PmergeMe(char **argv);

		~PmergeMe();

		PmergeMe &operator=(PmergeMe const &rhs);

		typedef typename Container::iterator iterator;

		void sort();
		void printData(const std::string &msg);
		void isSorted();


	private:
		Container mContainer;
		time_t mStart;
		time_t mEnd;
		int mComp;

		double time();
		void printPairs(size_t orderNum);
		void printMainChain(int posPend, int pairSize);
		int pairCompare();
		size_t countNumMoved(const Container &insertOrder, iterator endIt,
							 int bX);
		int getJacobsthal(int n);
		int getK(int bX, const Container &jacobSeq);
		size_t insertPair(int value, size_t pairSize, size_t numPairs);
		void insert(int pairSize, int numPend, Container &jacobSeq);
		Container insertOrder(int numPend, Container &jacobSeq);
		typename Container::reference getElement(typename Container::size_type index);
		typename Container::reference getElementOverload(typename Container::size_type index,
														 std::random_access_iterator_tag);

		typename Container::reference getElementOverload(typename Container::size_type index,
														 std::bidirectional_iterator_tag);
};

template < typename C >
std::ostream &operator<<(std::ostream &o, PmergeMe< C > const &i);

size_t getUsefulMain(int k, size_t posPend, size_t pairSize);
bool isMainChain(int i, int pairSize, int size);

#include "PmergeMe.cpp"

