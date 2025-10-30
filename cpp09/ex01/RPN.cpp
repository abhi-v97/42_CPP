#include "RPN.hpp"
#include <cstdlib>
#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	(void)src;
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
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, RPN const &i)
{
	(void)o, (void)i;
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
	if (mResult == 0)
		mResult = buffer.at(0) - '0';
	else
		mData.push(buffer.at(0) - '0');
}
void RPN::performOperation(std::string &buffer)
{
	if (mData.size() < 1)
		throw(std::runtime_error("not enough operands for operator " + buffer));
	int rhs = mData.top();
	mData.pop();
	int op = buffer.at(0);
	switch (op)
	{
	case '+': {
		mResult += rhs;
		break;
	}
	case '-': {
		mResult -= rhs;
		break;
	}
	case '*': {
		mResult *= rhs;
		break;
	}
	case '/': {
		mResult /= rhs;
		break;
	}
	}
}

int RPN::calculate(const std::string &expr)
{
	std::stringstream ss(expr);
	std::string buffer;

	for (; std::getline(ss, buffer, ' ');)
	{
		if (buffer.empty())
			continue;
		if (buffer.size() > 1 || checkInput(buffer))
		{
			throw(std::runtime_error("bad input given: " + buffer));
		}
		if (buffer.find("+-*/", 0, 1) != std::string::npos)
		{
			performOperation(buffer);
		}
		else
		{
			addNumber(buffer);
		}
	}
	return (mResult);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */