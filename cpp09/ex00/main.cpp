#include "BitcoinExchange.hpp"

int	main(void) {
	BitcoinExchange	exchange("data.csv", "queries.txt");

	std::cout << exchange.getDataFileContent() << std::endl;
	std::cout << exchange.getQueriesFileContent() << std::endl;

	return (0);
}
