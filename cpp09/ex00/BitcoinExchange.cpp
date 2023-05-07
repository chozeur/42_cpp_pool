#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {return ;}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
	return ;
}

BitcoinExchange::BitcoinExchange(const char* dataFileName, const char* queriesFileName)
: _dataFileName(dataFileName), _queriesFileName(queriesFileName) {

	_dataFile.open(_dataFileName);
	if (_dataFile.is_open()){
		std::string line;
		while (std::getline(_dataFile, line)) {
			_dataFileContent += line;
			_dataFileContent.push_back('\n');
		}
		_dataFile.close();
	} else {
		throw std::runtime_error("Error: could not open data file");
	}

	_queriesFile.open(_queriesFileName);
	if (_queriesFile.is_open()){
		std::string line;
		while (std::getline(_queriesFile, line)) {
			_queriesFileContent += line;
			_queriesFileContent.push_back('\n');
		}
		_queriesFile.close();
	} else {
		throw std::runtime_error("Error: could not open queries file");
	}

	return ;
}

BitcoinExchange::~BitcoinExchange(void) {return ;}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	(void)rhs;
	return (*this);
}

std::string		BitcoinExchange::getDataFileContent(void) const {return (_dataFileContent);}

std::string		BitcoinExchange::getQueriesFileContent(void) const {return (_queriesFileContent);}

