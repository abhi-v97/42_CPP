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

		typedef typename C::iterator iterator;
		typename C::iterator begin();
		typename C::iterator end();
		int getJacobsthal(int n);
		void sort();

	private:
		time_t mStart;
		time_t mEnd;
		C mContainer;
		double time();
		void sort(C &cont);
		std::string container_type();
		int mComp;
};

template < typename C >
std::ostream &operator<<(std::ostream &o, PmergeMe< C > const &i);

#include "PmergeMe.cpp"
