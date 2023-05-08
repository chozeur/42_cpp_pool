#include "BitcoinExchange.hpp"

const char*	dataFilename = "data.csv";

int	main(int ac, char** av, char** env) {

	(void)env;
	system("clear"); std::cout << std::endl << std::endl;

	if (ac != 2){
		std::cout << "Usage: " << av[0] << " <queries file>" << std::endl;
		return (42);
	}

	BitcoinExchange	exchange(dataFilename, av[1]);

	if (exchange.isDataFileValid() == false) {
		std::cout << "🔴 Data file is not valid" << std::endl << std::endl;
		return (42);
	} else {
		std::cout << "🟢 Data file is valid" << std::endl << std::endl;
	}

	if (exchange.isQueriesFileValid() == false) {
		std::cout << "🔴 Queries file is not valid" << std::endl << std::endl;
		return (42);
	} else {
		std::cout << "🟢 Queries file is valid" << std::endl << std::endl;
	}

	return (0);
}
