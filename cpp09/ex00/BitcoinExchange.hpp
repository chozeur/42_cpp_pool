#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <stdlib.h>
# include <utility>

# include <map>


class	BitcoinExchange {

	public:

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange(const char* dataFileName, const char* queriesFileName);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

		std::string						getDataFileContent(void) const;
		std::string*					getDataOrder(void) const;
		std::map<std::string, double>	getDataMap(void) const;
		std::string						getQueriesFileContent(void) const;
		std::map<std::string, double>	getQueriesMap(void) const;
		std::string*					getQueriesOrder(void) const;
		int								getQueriesCount(void) const;

		bool			isDataFileValid(void);		// no const because the map is filled here
		bool			isQueriesFileValid(void);	// no const because the map is filled here

		std::string		getRefDate(std::string date) const;

		static void			printMap(std::map<std::string, double> map);
		static bool			isDateValid(std::string date);
		static bool			isAmountValid(double amount);
		static bool			isInputValid(std::string input);
		static std::string	highestDate(std::string date1, std::string date2);

	private:


		std::fstream					_dataFile;
		const char*						_dataFileName;
		std::string						_dataFileContent;
		std::string*					_dataOrder;
		int								_dataCount;
		std::map<std::string, double>	_dataMap;

		std::fstream					_queriesFile;
		const char*						_queriesFileName;
		std::string						_queriesFileContent;
		std::string*					_queriesOrder;
		int								_queriesCount;
		std::map<std::string, double>	_queriesMap;

};

#endif
