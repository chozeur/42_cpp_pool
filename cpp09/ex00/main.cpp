#include "BitcoinExchange.hpp"

const char*	dataFilename = "data.csv";

int	main(int ac, char** av, char** env) {
	(void)env;

	system("clear"); std::cout << std::endl << "\033[1m" << "\033[4m" << "Bitcoin Exchange" << "\033[00m" << std::endl << std::endl;

	if (ac != 2){
		std::cout << "Usage: " << av[0] << " <queries file>" << std::endl;
		return (42);
	}

	BitcoinExchange exchange;

	try {
		exchange = BitcoinExchange(dataFilename, av[1]);
	} catch (std::exception &e) {
		std::cerr << "🔴 " << e.what() << std::endl << std::endl;
		return (42);
	}

	exchange.fillDataMapOrder();
	exchange.fillQueriesMapOrder();

	std::string			queries[exchange.getQueriesCount() + 1];
	std::stringstream	ss(exchange.getQueriesFileContent());
	int 				i = 0;
	while (getline(ss, queries[i++], '\n')) {}

	for (int i = 1; i < exchange.getQueriesCount(); ++i) {
		if (queries[i].size() == 0) {
			continue;
		}
		try {
			BitcoinExchange::checkInput(queries[i]);
			std::stringstream	ss(queries[i]);
			std::string			date;
			std::string			sep;
			double				amount;
			ss >> date >> sep >> amount;
			std::cout << "📅 " << date << " => " << amount * exchange.getDataMap()[exchange.getRefDate(date)] << std::endl;
		} catch (std::exception &e) {
			std::cerr << "❗ " << e.what() << std::endl;
		}
	}

	delete[] exchange.getDataOrder();
	delete[] exchange.getQueriesOrder();

	return (0);
}
