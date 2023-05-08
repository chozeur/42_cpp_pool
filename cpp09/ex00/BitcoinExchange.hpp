#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <stdlib.h>

# include <map>


class	BitcoinExchange {

	public:

		BitcoinExchange(const char* dataFileName, const char* queriesFileName);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &rhs);

		std::string						getDataFileContent(void) const;
		std::string						getQueriesFileContent(void) const;
		std::map<std::string, double>	getDataMap(void) const;

		bool			isDataFileValid(void);
		bool			isQueriesFileValid(void) const;

	private:

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);

		std::fstream	_dataFile;
		const char*		_dataFileName;
		std::string		_dataFileContent;

		std::fstream	_queriesFile;
		const char*		_queriesFileName;
		std::string		_queriesFileContent;

		std::map<std::string, double>	_dataMap;
};

#endif
