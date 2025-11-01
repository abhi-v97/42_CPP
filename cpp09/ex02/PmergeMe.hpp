#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>

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

	private:
		std::vector<int> mData;
};

std::ostream &operator<<(std::ostream &o, PmergeMe const &i);

#endif /* ******************************************************** PMERGEME_H */
