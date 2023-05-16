#ifndef	RPN_HPP
# define	RPN_HPP

# define RESET			"\033[37m"
# define BOLD			"\e[1m"
# define ITALIC			"\e[3m"
# define FORMAT_RESET	"\e[0m"
# define RED			"\033[38;5;196m"
# define GREEN			"\033[38;5;46m"
# define BLUE			"\033[38;5;51m"
# define BLU			"\033[38;5;152m"
# define ORANGE			"\033[38;5;214m"
# define PURPLE			"\033[38;5;98m"
# define YELLOW			"\033[38;5;220m"
# define PINK			"\033[38;5;205m"
# define WHITE			"\033[0;97m"

# include <iostream>
# include <stack>

class RPN {

	public:

		RPN(void);
		RPN(const RPN& src);
		RPN(const std::string& expression);
		~RPN(void);

		RPN& operator=(const RPN& rhs);

		std::string		getExpression(void) const;
		std::stack<double>	getStack(void) const;

		void	setExpression(const std::string& expression);
		void	setStack(const std::stack<double>& stack);

		void		compute(void);

		static bool	isValidExpression(const std::string expression);
		static int	count(const std::string& str, char c);
	private:

		std::string		_expression;
		std::stack<double>	_stack;

};


#endif
