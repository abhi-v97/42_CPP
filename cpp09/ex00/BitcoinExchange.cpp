#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime> // for tm struct to hold date info
#include <sstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() : mData()
{
	fillTable();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ) : mData()
{
	(void) src;
	fillTable();
}

BitcoinExchange::BitcoinExchange(const std::string &str) : mData(), file(str)
{
	(void) str;
	fillTable();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if (this != &rhs)
	{
		this->file = rhs.file;
		this->mData = rhs.mData;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & outf, BitcoinExchange const &obj)
{
	(void) obj;
	outf << "This program tracks bitcoin prices across dates";
	return outf;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int BitcoinExchange::getYear(std::string &date) const
{
	std::string yearStr = date.substr(0, date.find("-", 0));
	int year = std::atoi(yearStr.c_str());
	if (yearStr.empty() || year < 0)
	{
		throw (std::out_of_range(date + ": invalid date"));
	}
	return (year);
}

int BitcoinExchange::getMonth(std::string &date) const
{
	size_t lenYear = date.find("-", 0) + 1;
	size_t lenMon = date.find("-", lenYear) - lenYear;
	std::string monthStr = date.substr(lenYear, lenMon);
	int month = std::atoi(monthStr.c_str());
	if (monthStr.empty() || month < 1 || month > 12)
	{
		throw (std::out_of_range(date + ": invalid date"));
	}
	return (month);
}

int BitcoinExchange::getDay(std::string &date) const
{
	size_t lenDay = date.rfind("-");
	size_t lenMon = date.rfind("-", lenDay - 1);
	std::cout << lenMon << "lskdjf\n";
	return (0);
}
/**
	\details
	tm struct info: 
	tm_year is years since 1900
	tm_mon is months since Jan, so range 0-11
	tm_mday is day of the month, so 1-31
*/
void BitcoinExchange::checkDate(std::string &date) const
{
	if (date.empty())
	{
		throw(std::runtime_error("empty date string"));
	}
	std::string valid = "0123456789-"; 
	size_t pos = date.find_first_not_of(valid, 0);
	if (pos != date.npos)
	{
		throw(std::runtime_error(date + ": invalid date"));
	}
	
	tm tm = {};
	std::memset(&tm, 0, sizeof(tm));
	tm.tm_year = getYear(date) - 1900;
	tm.tm_mon = getMonth(date) - 1;
	tm.tm_mday = getDay(date);
}

void BitcoinExchange::checkValue(std::string &value) const
{

	std::cout << value << std::endl;
}

void BitcoinExchange::splitString(std::string &buffer) const
{
	std::stringstream temp(buffer);
	std::string date, value;

	std::getline(temp, date, ',');
	checkDate(date);
	std::getline(temp, value, ',');
	checkValue(value);
}

void BitcoinExchange::fillTable()
{
	std::ifstream input;
	std::string buffer;
	
	input.open("data.csv");
	if (input.fail())
		throw(std::runtime_error("Failed to open file"));

	std::getline(input, buffer);
	std::getline(input, buffer);

	splitString(buffer);
	// for (std::string line; std::getline(input, line);)
	// {
	// 	std::cout << line << std::endl;
	// }
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
