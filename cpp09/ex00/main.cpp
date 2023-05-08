#include "BitcoinExchange.hpp"

const char*	dataFilename = "data.csv";

int	main(int ac, char** av, char** env) {

	(void)env;

	if (ac != 2){
		std::cout << "Usage: " << av[0] << " <queries file>" << std::endl;
		return (42);
	}

	BitcoinExchange	exchange(dataFilename, av[1]);

	if (exchange.isQueriesFileValid() == false) {
		std::cout << "Queries file is not valid" << std::endl;
	}



	return (0);
}
