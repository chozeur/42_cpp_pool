#include "RPN.hpp"

int	main(int ac, char **av, char **env) {

	(void)env;

	if (ac != 2) {
		std::cout << std::endl
		<< ORANGE << BOLD
		<< "Usage:"
		<< WHITE << BOLD << ITALIC
		<< "\t./RPN\t< rpn_expression >"
		<< RESET << std::endl << std::endl;
		return (1);
	}

	if (!RPN::isValidExpression(av[1])) {
		std::cout << std::endl
		<< RED << BOLD
		<< "Invalid expression"
		<< RESET << std::endl << std::endl;
		return (1);
	}	RPN	rpn(av[1]);

	rpn.compute();

	std::cout << std::endl
	<< BLUE << "Result:\t\t"
	<< GREEN << rpn.getStack().top() << RESET << std::endl << std::endl;

	return (0);
}
