
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
			expr += std::string(argv[i]) + " ";
		}
		std::cout << "\"" << expr << "\"" << std::endl;
	}
	else
	{
		expr = std::string(argv[1]);
	}

	try
	{
		std::cout.precision(2);
		std::cout << calculator.calculate(expr) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
