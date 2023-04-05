#include "RPN.hpp"

RPN::RPN(void){
	return ;
}

RPN::RPN(const RPN& src){
	*this = src;
	return ;
}

RPN::RPN(std::string const & expression) : _expression(expression){
	return ;
}

RPN::~RPN(void){
	return ;
}

RPN& RPN::operator=(const RPN& rhs){
	if (this != &rhs){
		this->_expression = rhs._expression;
		this->_stack = rhs._stack;
	}
	return *this;
}

std::string	RPN::getExpression(void) const{
	return this->_expression;
}

std::stack<int>	RPN::getStack(void) const{
	return this->_stack;
}

void	RPN::setExpression(const std::string& expression){
	this->_expression = expression;
	return ;
}

void	RPN::setStack(const std::stack<int>& stack){
	this->_stack = stack;
	return ;
}

bool	RPN::isValidExpression(const std::string expression){
	int	num = 0;
	for (int i = 0; i < 10; ++i)
		num += count(expression, i + '0');
	int	op = count(expression, '+') + count(expression, '-') + count(expression, '*') + count(expression, '/');

	if (static_cast<size_t>(num + op + count(expression, ' ')) != expression.length())
		return false;

	if (expression[0] < '0' || expression[0] > '9')
		return false;

	if (num != op + 1)
		return false;

	return true;
}

void	RPN::compute(void){
	std::cout << std::endl
	<< BLUE << BOLD
	<< "Computing:\t"
	<< GREEN << BOLD
	<< this->_expression
	<< RESET << std::endl << std::endl;

	for (std::string::const_iterator it = this->_expression.begin(); it != this->_expression.end(); ++it){
		if (*it == ' '){
			continue;
		} else if (*it >= '0' && *it <= '9'){
			this->_stack.push(*it - '0');
		} else if (*it == '+'){
			int	a = this->_stack.top();
			this->_stack.pop();
			int	b = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(a + b);
		} else if (*it == '-'){
			int	a = this->_stack.top();
			this->_stack.pop();
			int	b = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(b - a);
		} else if (*it == '*'){
			int	a = this->_stack.top();
			this->_stack.pop();
			int	b = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(a * b);
		} else if (*it == '/'){
			int	a = this->_stack.top();
			this->_stack.pop();
			int	b = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(b / a);
		}
	}

	return ;
}

int	count(const std::string& str, char c){
	int	res = 0;
	for (size_t i = 0; i < str.length(); ++i)
		if (str[i] == c)
			res++;
	return res;
}
