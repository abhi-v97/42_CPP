

// References
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
// https://arxiv.org/pdf/1905.09656
// https://github.com/leske42/CPP09?tab=readme-ov-file#but-how-to-keep-track-of-my-pairs
// https://github.com/decidedlyso/merge-insertion-sort
#include "PmergeMe.hpp"
#include <bits/types/struct_timeval.h>
#include <list>
#include <sys/time.h>
#include <vector>

timeval getTimeStruct()
{
	struct timeval time;

	gettimeofday(&time, 0);
	return (time);
}

long getElapsedTime(const timeval &start, const timeval &end)
{
	long sec = end.tv_sec - start.tv_sec;
	long usec = end.tv_usec - start.tv_usec;

	return (sec * 1000000 + usec);
}

int main(int argc, char **argv)
{
	PmergeMe< std::vector< int > > vect;
	PmergeMe< std::list< int > > list;
	if (argc < 2)
	{
		std::cout << "Please enter a random sequence of positive integers" << std::endl;
		return (0);
	}
	else if (argc == 2)
	{
		try
		{
			vect = PmergeMe< std::vector< int > >(std::string(argv[1]));
			list = PmergeMe< std::list< int > >(std::string(argv[1]));
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (0);
		}
	}
	else if (argc > 2)
	{
		try
		{
			vect = PmergeMe< std::vector< int > >(argv);
			list = PmergeMe< std::list< int > >(argv);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (0);
		}
	}

	vect.printData("Before:\t");
	timeval start = getTimeStruct();
	vect.sort();
	timeval end = getTimeStruct();
	std::cout << "Time to process with std::vector<int> : " << getElapsedTime(start, end) << " us"
			  << std::endl;
	vect.isSorted();
	list.printData("Before:\t");
	start = getTimeStruct();
	list.sort();
	end = getTimeStruct();
	std::cout << "Time to process with std::list<int> : " << getElapsedTime(start, end) << " us"
			  << std::endl;
	list.isSorted();
	return (0);
}
