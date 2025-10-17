
#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
//
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
//
template <typename T> 
void addRandom(T &array, int n) {
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

int main()
{
	MutantStack<int> ms;

	addRandom(ms, 5);
	std::cout << "Random Stack:\t\t" << ms << std::endl;
	std::cout << "iter test:\t\t";
	printStack(ms.begin(), ms.end());

	std::cout << "reverse test:\t\t";
	printStack(ms.rbegin(), ms.rend());
	std::cout << std::endl;

	const MutantStack<int, std::list<int> > ms2;
	addRandom(ms2, 10);
	std::cout << "Random Const Stack:\t" << ms2 << std::endl;
	std::cout << "iter test:\t\t";
	printStack(ms2.begin(), ms2.end());

	std::cout << "reverse test:\t\t";
	printStack(ms2.rbegin(), ms2.rend());
	std::cout << std::endl;
	return (0);
}

