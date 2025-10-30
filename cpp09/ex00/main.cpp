#include <exception>
#include <fstream>
#include <stdexcept>

#include "BitcoinExchange.hpp"

void evaluateInput(const std::string &file, BitcoinExchange &btc)
{
	std::ifstream input;
	std::string buffer;

	input.open(file.c_str());
	if (input.fail())
	{
		throw(std::runtime_error("failed to open file: " + file));
	}
	for (; std::getline(input, buffer);)
	{
		std::string date, value;
		size_t sepPos = buffer.find("|", 0);
		if (sepPos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << buffer << std::endl;
		}
		else
		{
			try
			{
				date = buffer.substr(0, sepPos - 1);
				value = buffer.substr(sepPos + 2, buffer.size() - (sepPos + 1));
				btc.evaluate(date, value);
			}
			catch (std::exception &e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	BitcoinExchange btc = BitcoinExchange(argv[1]);
	try
	{
		evaluateInput(std::string(argv[1]), btc);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
