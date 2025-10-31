#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ctime> // for tm struct to hold date info
#include <iostream>
#include <map>
#include <string>

/*
 * \class BitcoinExchange
 * Reads bitcoin prices from data.csv on construction and stores them in a map
 * container. The evaluate() function can be used to retrieve the price of
 * bitcoin on a given date.
 */
class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange(std::string const &str);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		void evaluate(std::string &date, std::string &num);

	private:
		std::time_t checkDate(std::string &str) const;
		double checkValue(std::string &buffer) const;
		void fillTable(void);
		std::time_t setClosestDate(std::time_t inputDate);
		void splitString(std::string &line);
		void addEntry(std::time_t &date, double &value);
		int getYear(std::string &date) const;
		int getMonth(std::string &date) const;
		int getDay(std::string &date) const;

		std::map<std::time_t, double> mData;
		std::string mFile;
};

std::ostream &operator<<(std::ostream &o, BitcoinExchange const &i);

#endif /* ************************************************* BITCOINEXCHANGE_H */
