#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );
		
		int calculate(const std::string &expr);

	private:
		void performOperation(std::string &buffer);
		void addNumber(std::string &buffer);
		std::stack<int> mData;
		int mResult;

};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif /* ************************************************************* RPN_H */