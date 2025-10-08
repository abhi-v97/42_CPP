#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

# include <deque>
# include <stack>

template <typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U>
{
public:

	typedef typename U::iterator iterator;
	typedef typename U::const_iterator const_iterator;
	typedef typename U::reverse_iterator reverse_iterator;
	typedef typename U::const_reverse_iterator reverse_const_iterator;

	MutantStack() : std::stack<T, U>() {};
	MutantStack(const MutantStack &src) : std::stack<T, U>(src) { (void)src; };
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

# include "MutantStack.tpp"

#endif

