#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() : mData()
{
	fillTable();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : mData()
{
	this->mData = src.mData;
	this->mFile = src.mFile;
}

BitcoinExchange::BitcoinExchange(const std::string &str) : mData(), mFile(str)
{
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

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->mFile = rhs.mFile;
		this->mData = rhs.mData;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &outf, BitcoinExchange const &obj)
{
	(void)obj;
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
	if (yearStr.empty() || year < 0 || year > 2100)
	{
		throw(std::out_of_range(date + ": invalid date"));
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
		throw(std::out_of_range(date + ": invalid date"));
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
		throw(std::out_of_range(date + ": invalid date"));
	}
	return (day);
}

/**
  Converts date from std::string into epoch time

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
		throw(std::runtime_error("Error: bad input => " + date));
	}

	tm tm = {};
	std::memset(&tm, 0, sizeof(tm));
	tm.tm_year = getYear(date) - 1900;
	tm.tm_mon = getMonth(date) - 1;
	tm.tm_mday = getDay(date);
	std::time_t t = std::mktime(&tm);
	return (t);
}

/**
	\brief Checks value string in data.csv

	Subject says value must be between 0-1000, but I'm assuming that's only for
	input.txt, not data.csv
*/
double BitcoinExchange::checkValue(std::string &value) const
{
	std::string valid = "0123456789.-";
	size_t pos = value.find_first_not_of(valid, 0);
	if (pos != value.npos)
	{
		throw(std::runtime_error("Error: bad input => " + value));
	}

	double result = std::strtod(value.c_str(), NULL);
	if (result > std::numeric_limits<int>::max())
	{
		throw(std::out_of_range("too large a number."));
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
	addEntry(date, value);
}

/**
 * \brief goes through each line in data.csv and attempts to convert the info
 * into map<time_t, double> format.
 *
 * If an exception is thrown, discards the current line and moves onto the next
 * one.
 */
void BitcoinExchange::fillTable()
{
	std::ifstream input;
	std::string line;

	input.open("data.csv");
	if (input.fail())
		throw(std::runtime_error("Failed to open file"));

	std::getline(input, line);

	for (std::string line; std::getline(input, line);)
	{
		try
		{
			splitString(line);
		}
		catch (std::exception &e)
		{
		}
	}
	if (mData.empty())
		throw(std::runtime_error("No valid data entered"));
}

/**
 * \brief searches the map container for inputDate. If not found, it will return
 * the closest date that's lower than inputDate.
 */
std::time_t BitcoinExchange::setClosestDate(std::time_t inputDate)
{
	std::map<std::time_t, double>::iterator it;

	if (inputDate < mData.begin()->first)
	{
		return (mData.begin()->first);
	}
	it = mData.lower_bound(inputDate);
	if (it->first == inputDate)
		return (it->first);
	it--;
	if (it == mData.begin())
		return (mData.begin()->first);
	return (it->first);
}

/**
 * \brief prints the total worth of given bitcoin on the given date, if valid
 *
 * \param inputDateStr date string which is used to determine the value of bitcoin
 * \param inputValueStr total amount of bitcoin
 */
void BitcoinExchange::evaluate(std::string &inputDateStr, std::string &inputValueStr)
{
	std::time_t inputDate = checkDate(inputDateStr);
	double inputValue = checkValue(inputValueStr);
	if (inputValue < 0)
	{
		throw(std::out_of_range("Error: not a positive number."));
	}
	else if (inputValue > 1000)
	{
		throw(std::out_of_range("Error: too large a number."));
	}
	std::time_t closestDate = setClosestDate(inputDate);
	double exchangeValue = mData[closestDate] * std::strtod(inputValueStr.c_str(), NULL);
	// std::cout.precision(2);
	std::cout << inputDateStr << " => " << inputValue << " = " << exchangeValue << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
