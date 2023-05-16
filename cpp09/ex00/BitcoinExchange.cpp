#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {return ;}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
	return ;
}

BitcoinExchange::BitcoinExchange(const char* dataFileName, const char* queriesFileName)
: _dataFileName(dataFileName), _dataCount(-1), _queriesFileName(queriesFileName), _queriesCount(0) {

	_dataFile.open(_dataFileName);
	if (_dataFile.is_open()){
		std::string line;
		while (std::getline(_dataFile, line)) {
			_dataFileContent += line;
			_dataFileContent.push_back('\n');
			++_dataCount;
		}
		_dataFile.close();
	} else {
		throw std::runtime_error("Error: could not open data file");
	}
	_dataOrder = new std::string[_dataCount];

	_queriesFile.open(_queriesFileName);
	if (_queriesFile.is_open()){
		std::string line;
		while (std::getline(_queriesFile, line)) {
			_queriesFileContent += line;
			_queriesFileContent.push_back('\n');
			++_queriesCount;
		}
		_queriesFile.close();
	} else {
		throw std::runtime_error("Error: could not open queries file");
	}
	_queriesOrder = new std::string[_queriesCount];

	return ;
}

BitcoinExchange::~BitcoinExchange(void) {
	_dataFile.close();
	_queriesFile.close();
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs){
		_dataFile.close();
		_dataFile.open(rhs._dataFileName);
		_dataFileName = rhs._dataFileName;
		_dataFileContent = rhs._dataFileContent;
		_dataOrder = rhs._dataOrder;	// no deep copy because it's a pointer to an array
		_dataCount = rhs._dataCount;
		_dataMap = rhs._dataMap;
		_queriesFile.close();
		_queriesFile.open(rhs._queriesFileName);
		_queriesFileName = rhs._queriesFileName;
		_queriesFileContent = rhs._queriesFileContent;
		_queriesOrder = rhs._queriesOrder;	// no deep copy because it's a pointer to an array
		_queriesCount = rhs._queriesCount;
		_queriesMap = rhs._queriesMap;
	}
	return (*this);
}

std::string						BitcoinExchange::getDataFileContent(void) const {return (_dataFileContent);}

std::string*					BitcoinExchange::getDataOrder(void) const {return (_dataOrder);}

std::map<std::string, double>	BitcoinExchange::getDataMap(void) const {return (_dataMap);}

int								BitcoinExchange::getDataCount(void) const {return (_dataCount);}

std::string						BitcoinExchange::getQueriesFileContent(void) const {return (_queriesFileContent);}

std::map<std::string, double>	BitcoinExchange::getQueriesMap(void) const {return (_queriesMap);}

std::string*					BitcoinExchange::getQueriesOrder(void) const {return (_queriesOrder);}

int								BitcoinExchange::getQueriesCount(void) const {return (_queriesCount);}

std::string	BitcoinExchange::getRefDate(std::string date) const {
	std::string	refDate = "2009-01-02";
	for (int i = 0; i < _dataCount; ++i) {
		if (_dataOrder[i] == date) {
			return (date);
		} else if (BitcoinExchange::highestDate(_dataOrder[i], date) == date) {
			refDate = _dataOrder[i];
		} else {
			return (refDate);
		}
	}
	return (refDate);
}

void	BitcoinExchange::fillDataMapOrder(void){
	std::istringstream			iss(_dataFileContent);
	std::string					token;
	int							i = 0;
	while (std::getline(iss, token, '\n')) {
		// skip empty lines
		if (i > 0 && token.size() == 0) {
			continue;
		}
		// skip first line
		if (i != 0) {
			std::string					data[2];
			std::istringstream			iss2(token);
			std::string					token2;
			int							j = 0;
			while (std::getline(iss2, token2, ',')) {
				if (j > 1) {
					throw std::runtime_error("Unexpected error");
				}
				// skip white spaces
				if (token2.size() != 0){
					data[j++] = token2;
				}
			}
			std::stringstream	ss(data[1]);
			double				d;
			ss >> d;
			_dataMap[data[0]] = d;
			_dataOrder[i - 1] = data[0];
		}
		++i;
	}
	return ;
}

void	BitcoinExchange::fillQueriesMapOrder(void) {
	std::istringstream			iss(_queriesFileContent);
	std::string					token;
	int							i = 0;
	while (std::getline(iss, token, '\n')) {
		// skip empty lines
		if (i > 0 && token.size() == 0) {
			continue;
		}
		// skip first line
		if (i != 0) {
			std::string					data[3];
			std::istringstream			iss2(token);
			std::string					token2;
			int							j = 0;
			while (std::getline(iss2, token2, ' ')) {
				if (j > 2) {
					throw std::runtime_error("Unexpected error");
				}
				// skip white spaces
				if (token2.size() != 0){
					data[j++] = token2;
				}
			}
			std::stringstream	ss(data[2]);
			double				d;
			ss >> d;
			_queriesMap[data[0]] = d;
			_queriesOrder[i - 1] = data[0];
		}
		++i;
	}
	return ;
}

void	BitcoinExchange::printMap(std::map<std::string, double> map) {
	for (std::map<std::string, double>::const_iterator it = map.begin(); it != map.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	return ;
}

bool	BitcoinExchange::isDateValid(std::string date) {
	std::stringstream	ss(date);
	int					y, m, d;
	char				c1, c2;
	ss >> y >> c1 >> m >> c2 >> d;
	if (ss.fail() || c1 != '-' || c2 != '-' || ss.peek() != EOF) {
		return (false);
	} else if (y < 2009) {
		return (false);
	} else if (y == 2009 && m == 1 && d < 2) {
		return (false);
	} else if (m < 1 || m > 12) {
		return (false);
	} else if (d < 1 || d > 31) {
		return (false);
	} else if (d >= 29 && m == 2 && y % 4 != 0) {
		return (false);
	} else if (d >= 31 && (m == 4 || m == 6 || m == 9 || m == 11)) {
		return (false);
	} else {return (true);}
}

bool	BitcoinExchange::isAmountValid(std::string amount) {
	int	dotCount = 0;
	for (std::string::const_iterator it = amount.begin(); it != amount.end(); ++it) {
		if (*it == '.') {
			++dotCount;
		}
		if (*it < '0' || *it > '9') {
			if (*it != '.' || dotCount > 1) {
				return (false);
			}
		}
	}
	std::stringstream	ss(amount);
	double				a;
	ss >> a;
	if (a < 0 || a > 1000) {
		return (false);
	}
	return (true);
}

void	BitcoinExchange::checkInput(std::string input){
	std::string					data[3];
	std::istringstream			iss(input);
	std::string					token;
	int							i = 0;
	while (std::getline(iss, token, ' ')) {
		if (i > 2) {
			throw	std::runtime_error("Error: too many arguments in line");
		}
		if (token.size() != 0){
			data[i++] = token;
		}
	} if (i != 3 || data[1] != "|"){
		throw	std::runtime_error("Error: wrong input format");
	}

	if (!BitcoinExchange::isDateValid(data[0])) {
		throw	std::runtime_error("Error: date is not valid (" + data[0] + ")");
	} else if (!BitcoinExchange::isAmountValid(data[2])) {
		throw	std::runtime_error("Error: amount is not valid (" + data[2] + ")");
	}

	return ;
}

std::string	BitcoinExchange::highestDate(std::string date1, std::string date2) {
	std::stringstream	ss1(date1);
	std::stringstream	ss2(date2);
	int					y1, m1, d1;
	int					y2, m2, d2;
	char				c1, c2;
	ss1 >> y1 >> c1 >> m1 >> c2 >> d1;
	ss2 >> y2 >> c1 >> m2 >> c2 >> d2;
	if (y1 > y2) {
		return (date1);
	} else if (y1 < y2) {
		return (date2);
	} else if (m1 > m2) {
		return (date1);
	} else if (m1 < m2) {
		return (date2);
	} else if (d1 > d2) {
		return (date1);
	} else if (d1 < d2) {
		return (date2);
	} else {return (date1);}
}
