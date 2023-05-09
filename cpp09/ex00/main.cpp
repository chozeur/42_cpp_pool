#include "BitcoinExchange.hpp"

const char*	dataFilename = "data.csv";

int	main(int ac, char** av, char** env) {

	(void)env;
	system("clear"); std::cout << std::endl << std::endl;

	if (ac != 2){
		std::cout << "Usage: " << av[0] << " <queries file>" << std::endl;
		return (42);
	}

	BitcoinExchange exchange;
	try {
		exchange = BitcoinExchange(dataFilename, av[1]);
	} catch (std::exception &e) {
		return (42);
	}

	int	size = exchange.getQueriesCount();
	std::cout << "ℹ️ Queries count: " << size << std::endl << std::endl;
	for (int i = 0; i < size; ++i) {

		std::string date = exchange.getQueriesOrder()[i];
		if (BitcoinExchange::isDateValid(date)) {
			std::string refDate = exchange.getRefDate(date);
			double refPrice = exchange.getDataMap()[refDate];
			if (BitcoinExchange::isAmountValid(refPrice)) {

				std::cout << "🔘 " << date << " => " << refPrice * exchange.getQueriesMap()[date] << std::endl << std::endl;

				if (refDate == date) {
					std::cout << "";
				} else {
					std::cout << "";
				}
			} else {
				std::cout << "🔴 [" << refPrice << "] is not a valid amount" << std::endl << std::endl;
				continue ;
			}
		} else {
			std::cout << "🔴 [" << date << "] is not a valid date" << std::endl << std::endl;
			continue ;
		}
	}

	delete[] exchange.getDataOrder();
	delete[] exchange.getQueriesOrder();

	return (0);
}
