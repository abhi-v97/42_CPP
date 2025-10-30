
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN calculator = RPN();
	std::string expr = std::string();

	if (argc < 2)
	{
		std::cout << "No expression given" << std::endl;
		return (0);
	}
	else if (argc > 2)
	{
		for (int i = 1; argv[i]; i++)
		{
			expr = expr + std::string(argv[i]) + " ";
		}
		std::cout << "\"" << expr << "\"" << std::endl;
	}
	
	calculator.calculate(expr);
	return (0);
}
