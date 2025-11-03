
#include "MutantStack.hpp"
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

int subject()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

template <typename T>
void addRandom(T &array, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		array.push((rand() % (101)));
}

template <typename Iter>
void printStack(Iter begin, Iter end)
{
	std::cout << "{ ";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << "}" << std::endl;
}

template <typename T>
void testConstIter(T &array)
{
	typename T::const_iterator ci;
	std::cout << "{ ";
	for (ci = array.begin(); ci != array.end(); ci++)
		std::cout << *ci << " ";
	std::cout << "}" << std::endl;
}

int main()
{
	MutantStack<int> ms;

	addRandom(ms, 5);
	std::cout << "Default Int Stack:\t\t\t" << std::endl;
	std::cout << "iter test:\t\t\t";
	printStack(ms.begin(), ms.end());

	std::cout << "reverse test:\t\t\t";
	printStack(ms.rbegin(), ms.rend());
	std::cout << std::endl;

	MutantStack<char, std::list<char>> ms2;
	ms2.push('a');
	ms2.push('z');
	ms2.push('C');
	ms2.push('0');
	ms2.push('4');
	ms2.push('5');
	ms2.push('1');
	std::cout << "Char List Stack:\t\t\t" << std::endl;
	std::cout << "iter test:\t\t\t";
	printStack(ms2.begin(), ms2.end());

	std::cout << "reverse test:\t\t\t";
	printStack(ms2.rbegin(), ms2.rend());
	std::cout << std::endl;

	MutantStack<std::string, std::deque<std::string>> ms3;
	ms3.push("hello");
	ms3.push("world");
	ms3.push("!");
	ms3.push("bonjour");
	ms3.push("mes");
	ms3.push("amis");
	std::cout << "Deque Stack:\t\t\t" << std::endl;
	std::cout << "const iterator test:\t\t";
	MutantStack<std::string, std::deque<std::string>>::const_iterator ci = ms3.begin();
	MutantStack<std::string, std::deque<std::string>>::const_iterator ci_end = ms3.end();
	printStack(ci, ci_end);
	std::cout << "const reverse iterator test:\t";
	MutantStack<std::string, std::deque<std::string>>::reverse_const_iterator cri = ms3.rbegin();
	MutantStack<std::string, std::deque<std::string>>::reverse_const_iterator cri_end = ms3.rend();
	printStack(cri, cri_end);
	std::cout << std::endl;

	MutantStack<double, std::vector<double>> ms4;
	addRandom(ms4, 3);
	std::cout << "Vector String Stack:\t\t" << ms4 << std::endl;
	MutantStack<double, std::vector<double>>::iterator it = ms4.begin();
	std::cout << "*it\t\t\t\t" << "{ " << *it << " }" << std::endl;
	std::cout << "*(it + 1)\t\t\t" << "{ " << *(it + 1) << " }" << std::endl;
	std::cout << "*(it + 2)\t\t\t" << "{ " << *(it + 2) << " }" << std::endl;
	std::cout << std::endl;

	std::cout << "Copy constructor test" << std::endl;
	MutantStack<double, std::vector<double>> ms5(ms4);
	it = ms5.begin();
	for (; it != ms5.end(); it++)
		*it = 42.42;
	std::cout << "Vector Stack (unmodified):\t" << ms4 << std::endl;
	std::cout << "Copy constructor obj:\t\t" << ms5 << std::endl;
	return (0);
}
