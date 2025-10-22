#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

# include <deque>
# include <stack>
# include <iostream>

template <typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
public:

	typedef typename U::iterator iterator;
	typedef typename U::const_iterator const_iterator;
	typedef typename U::reverse_iterator reverse_iterator;
	typedef typename U::const_reverse_iterator reverse_const_iterator;

	MutantStack<T, U>() : std::stack<T, U>() {};
	MutantStack<T, U>(const MutantStack<T, U> &src) : std::stack<T, U>(src) { (void)src; };
	~MutantStack() {};

	MutantStack &operator=(const MutantStack &obj)
	{
		if (this != &obj)
			this->c = obj.c;
		return (*this);
	}

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
	reverse_iterator rbegin() { return (this->c.rbegin()); }
	reverse_iterator rend() { return (this->c.rend()); }
	
	const_iterator begin() const { return (this->c.begin()); }
	reverse_const_iterator rbegin() const { return (this->c.rbegin()); }
	const_iterator end() const { return (this->c.end()); }
	reverse_const_iterator rend() const { return (this->c.rend()); }
};

template <typename T, typename U>
std::ostream &operator<<( std::ostream & o, const MutantStack<T, U> &ms)
{
	o << "{ ";
	typename  MutantStack<T, U>::const_iterator it = ms.begin();
	for (; it != ms.end(); it++)
	{
		o << *it << " ";
	}
	o << "}";
	return (o);
}

#endif
