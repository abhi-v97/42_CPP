

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91

#include "PmergeMe.hpp"
#include <vector>

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "Please enter a random sequence of positive integers" << std::endl;
		return (0);
	}
	else if (argc == 2)
	{
		PmergeMe<std::vector<int> > pm = PmergeMe<std::vector<int> >(std::string(argv[1]));
		pm.printData("Before:\t");
	}
	else if (argc > 2)
	{
		// PmergeMe pm = PmergeMe(argv);
	}
	return (0);
}
