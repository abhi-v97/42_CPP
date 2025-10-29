#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	
	BitcoinExchange btc = BitcoinExchange(argv[1]);
	return (0);
}