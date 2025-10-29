#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange(std::string const &str);
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

	private:
		void checkDate(std::string &str) const;
		void checkValue(std::string &str) const;
		void fillTable(void);

		void splitString(std::string &buffer) const;
		int getYear(std::string &date) const;
		int getMonth(std::string &date) const;
		int getDay(std::string &date) const;

		std::map<std::string, float> mData;
		std::string file;

};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */
