#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{

	public:
		RPN();
		RPN(RPN const &src);
		~RPN();

		RPN &operator=(RPN const &rhs);

		double calculate(const std::string &expr);

	private:
		void performOperation(std::string &buffer);
		void addNumber(std::string &buffer);
		std::stack<double> mData;
};

std::ostream &operator<<(std::ostream &o, RPN const &i);

#endif /* ************************************************************* RPN_H */
