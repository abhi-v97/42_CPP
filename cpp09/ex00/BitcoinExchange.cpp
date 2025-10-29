#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
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
	std::string dayStr = date.substr(lenDay + 1, date.size() - lenDay);
	int day = std::atoi(dayStr.c_str());
	if (dayStr.empty() || day < 1 || day > 31)
	{
		throw (std::out_of_range(date + ": invalid date"));
	}
	return (day);
}
/**
	\details
	tm struct info: 
	tm_year is years since 1900
	tm_mon is months since Jan, so range 0-11
	tm_mday is day of the month, so 1-31
*/
std::time_t BitcoinExchange::checkDate(std::string &date) const
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
	std::time_t t = std::mktime(&tm);
	return (t);
}

double BitcoinExchange::checkValue(std::string &buffer) const
{
	double result = std::strtod(buffer.c_str(), NULL);
	if (result < 0 || result > 1000)
	{
		throw(std::out_of_range("value out of range"));
	}
	return (result);
}

void BitcoinExchange::addEntry(std::time_t &date, double &value)
{
	std::map<std::time_t, double>::iterator it;
	it = mData.find(date);
	if (it == mData.end())
	{
		mData[date] = value;
	}
	else
	{
		it->second = value;
	}
}

void BitcoinExchange::splitString(std::string &line)
{
	std::stringstream temp(line);
	std::string buffer;
	std::time_t date;
	double value;

	std::getline(temp, buffer, ',');
	date = checkDate(buffer);
	std::getline(temp, buffer, ',');
	value = checkValue(buffer);
	// std::cout << "date: " << date << ", value: " << value << std::endl;
	addEntry(date, value);
}

void BitcoinExchange::fillTable()
{
	std::ifstream input;
	std::string line;
	
	input.open("data.csv");
	if (input.fail())
		throw(std::runtime_error("Failed to open file"));

	std::getline(input, line);
	std::getline(input, line);

	for (std::string line; std::getline(input, line);)
	{
		try
      		{
			splitString(line);
		} catch (std::exception &e) {}
	}
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
