#include "RPN.hpp"

int	main(int ac, char **av, char **env) {

	(void)env;

	if (ac != 2) {
		std::cout << std::endl << "Usage: ./RPN <rpn expression>" << std::endl << std::endl;
		return (1);
	}

	if (!RPN::isValidExpression(av[1])) {
		std::cout << std::endl << RED << BOLD << "Invalid expression" << RESET << std::endl << std::endl;
		return (1);
	}	RPN	rpn(av[1]);

	rpn.compute();

	std::cout << std::endl << BLUE << "Result: " << GREEN << rpn.getStack().top() << RESET << std::endl << std::endl;

	return (0);
}
