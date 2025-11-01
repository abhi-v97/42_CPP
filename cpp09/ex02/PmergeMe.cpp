#include "PmergeMe.hpp"
#include <cstdlib>
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}

PmergeMe::PmergeMe(const std::string &str)
{
	std::stringstream ss(str);
	std::string buffer;

	for (; std::getline(ss, buffer, ' ');)
	{
		mData.push_back(std::atoi(buffer.c_str()));
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	// if ( this != &rhs )
	//{
	// this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &operator<<(std::ostream &o, PmergeMe const &i)
{
	(void)o, (void)i;
	// o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PmergeMe::printData(const std::string &msg)
{
	std::cout << msg;
	for (size_t i = 0; i < mData.size(); i++)
		std::cout << mData.at(i) << ' ';
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
