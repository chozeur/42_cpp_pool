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

bool			BitcoinExchange::isQueriesFileValid(void) const {

	int	queriesCount = 0;
	for (std::string::const_iterator it = _queriesFileContent.begin(); it != _queriesFileContent.end(); ++it) {
		std::string	query;
		while (*it != '\n' && it != _queriesFileContent.end()) {
			query.push_back(*it);
			++it;
		}
		if (query.size() != 0) {
			++queriesCount;
		}
	}

	std::cout << "queriesCount: " << queriesCount << std::endl;

	std::string	queries[queriesCount];
	int			tmpQC = queriesCount;
	for (std::string::const_iterator it = _queriesFileContent.begin(); it != _queriesFileContent.end(); ++it) {
		std::string	query;
		while (*it != '\n' && it != _queriesFileContent.end()) {
			query.push_back(*it);
			++it;
		}
		if (query.size() != 0) {
			queries[tmpQC - 1] = query;
			--tmpQC;
		}
	}

	for (int i = 0; i < queriesCount; ++i) {
		std::cout << queries[i] << std::endl;
		std::string	data[3];
		std::istringstream			iss(queries[i]);
		std::string					token;
		int							j = 0;
		while (std::getline(iss, token, ' ')) {
			if (j > 2) {
				return (false);
			}
			if (token.size() != 0){
				data[j++] = token;
			}
		}

		if (data[0].size() != 10) {
			return (false);
		} else if (data[0][4] != '-' || data[0][7] != '-') {
			return (false);
		} else if (data[0][0] < '0' || data[0][0] > '9') {
			return (false);
		} else if (data[0][1] < '0' || data[0][1] > '9') {
			return (false);
		} else if (data[0][2] < '0' || data[0][2] > '9') {
			return (false);
		} else if (data[0][3] < '0' || data[0][3] > '9') {
			return (false);
		} else if (data[0][5] < '0' || data[0][5] > '9') {
			return (false);
		} else if (data[0][6] < '0' || data[0][6] > '9') {
			return (false);
		} else if (data[0][8] < '0' || data[0][8] > '9') {
			return (false);
		} else if (data[0][9] < '0' || data[0][9] > '9') {
			return (false);
		} else if (data[1] != "|"){
			return (false);
		} else if (42) {
			int	dotCount = 0;
			for (std::string::const_iterator it = data[2].begin(); it != data[2].end(); ++it) {
				if (*it == '.') {
					++dotCount;
				}
				if (*it < '0' || *it > '9') {
					if (*it != '.' || dotCount > 1) {
						return (false);
					}
				}
			}
		}
	}

	return (true);
}
