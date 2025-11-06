#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() : mData(std::stack<double>())
{
}

RPN::RPN(const RPN &src) : mData(src.mData)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		this->mData = rhs.mData;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, RPN const &i)
{
	(void)i;
	o << "this class takes a Reverse Polish Notation expression and returns its result";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int checkInput(std::string &buffer)
{
	if (buffer.find_first_not_of("01234567890+-*/") != std::string::npos)
		return (1);
	return (0);
}

void RPN::addNumber(std::string &buffer)
{
	mData.push(buffer.at(0) - '0');
}
void RPN::performOperation(std::string &buffer)
{
	if (mData.size() < 2)
		throw(std::runtime_error("not enough operands for operator " + buffer));
	double rhs = mData.top();
	mData.pop();
	int op = buffer.at(0);
	switch (op)
	{
	case '+': {
		mData.top() = mData.top() + rhs;
		break;
	}
	case '-': {
		mData.top() = mData.top() - rhs;
		break;
	}
	case '*': {
		mData.top() = mData.top() * rhs;
		break;
	}
	case '/': {
		if (rhs == 0)
			throw(std::runtime_error("divide by zero"));
		mData.top() = mData.top() / rhs;
		break;
	}
	}
}

double RPN::calculate(const std::string &expr)
{
	std::stringstream ss(expr);
	std::string buffer;

	for (; std::getline(ss, buffer, ' ');)
	{
		if (buffer.empty())
			continue ;
		if (buffer.at(0) == '-' && buffer.size() == 2)
		{
			int i = buffer.at(1) - '0';
			mData.push(-i);
			continue ;
		}
		if (buffer.size() > 1 || checkInput(buffer))
		{
			throw(std::runtime_error("bad input given: " + buffer));
		}
		if (buffer.find_first_of("+-*/") != std::string::npos)
		{
			performOperation(buffer);
		}
		else
		{
			addNumber(buffer);
		}
	}
	return (mData.top());
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
