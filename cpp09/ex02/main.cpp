

// References
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://arxiv.org/pdf/1905.09656
// https://github.com/leske42/CPP09?tab=readme-ov-file#but-how-to-keep-track-of-my-pairs
// https://github.com/decidedlyso/merge-insertion-sort
#include "PmergeMe.hpp"
#include <vector>
#include <list>

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "Please enter a random sequence of positive integers" << std::endl;
		return (0);
	}
	else if (argc == 2)
	{
		PmergeMe< std::vector< int > > pm = PmergeMe< std::vector< int > >(std::string(argv[1]));
		pm.printData("Before:\t");
		// TEST: Jacobsthal sequence
		// for (int i = 0; i < 20; i++)
		// 	std::cout << pm.getJacobsthal(i) << std::endl;
		pm.sort();
		pm.isSorted();
	}
	else if (argc > 2)
	{
		PmergeMe< std::vector< int > > pm = PmergeMe< std::vector< int > >(argv);
		// PmergeMe< std::list<int> > pm = PmergeMe< std::list<int> >(argv);
		pm.printData("Before:\t");
		// TEST: Jacobsthal sequence
		// for (int i = 0; i < 20; i++)
		// 	std::cout << pm.getJacobsthal(i) << std::endl;
		pm.sort();
		pm.isSorted();
	}
	return (0);
}
