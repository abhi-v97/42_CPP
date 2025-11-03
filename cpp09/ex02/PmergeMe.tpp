#pragma once

#include "PmergeMe.hpp"
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <algorithm>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename C> PmergeMe<C>::PmergeMe() {}

template <typename C> PmergeMe<C>::PmergeMe(const PmergeMe &src) { (void)src; }

template <typename C> PmergeMe<C>::PmergeMe(const std::string &str) {
  std::stringstream ss(str);
  std::string buffer;

  for (; std::getline(ss, buffer, ' ');) {
    mContainer.push_back(std::atoi(buffer.c_str()));
  }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename C> PmergeMe<C>::~PmergeMe() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename C> PmergeMe<C> &PmergeMe<C>::operator=(PmergeMe const &rhs) {
  (void)rhs;
  // if ( this != &rhs )
  //{
  // this->_value = rhs.getValue();
  //}
  return *this;
}

template <typename C>
std::ostream &operator<<(std::ostream &o, PmergeMe<C> const &i) {
  (void)o, (void)i;
  // o << "Value = " << i.getValue();
  return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename C> void PmergeMe<C>::printData(const std::string &msg) {
  std::cout << msg;
  for (size_t i = 0; i < mContainer.size(); i++)
    std::cout << mContainer.at(i) << ' ';
  std::cout << std::endl;
}

template <typename C>
int PmergeMe<C>::getJacobsthal(int n)
{
  return ((std::pow(2, n) - std::pow(-1, n)) / 3);
}

template <typename C>
void PmergeMe<C>::sort()
{
  static size_t orderNum = 2;

  int units = mContainer.size() / orderNum;

  if (units < 2)
    return ;

  bool oddPair = units % 2 == 1;
  (void) oddPair;

iterator begin = mContainer.begin();
iterator end = mContainer.begin() + ((orderNum * units) - (orderNum * oddPair));
for (iterator it = begin; it < end; it += (orderNum * 2))
  {
    if (*(it + orderNum - 1) > *(it + orderNum * 2 - 1))
	{
		for (size_t i = 0; i < orderNum; i++)
        	std::swap(*(it + i), *(it + i + orderNum));
  	}
}
  
  std::cout << "Order num: " << orderNum << std::endl;
  printData("");

  orderNum *= 2;

  sort();

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
