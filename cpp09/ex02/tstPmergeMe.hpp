#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
# include <cstdlib>
# include <vector>
#include <iterator>
# include <list>

class	PmergeMe {

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe(int ac, char **av);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &rhs);

		std::vector<int>	getVector(void) const;
		std::list<int>		getList(void) const;

		void	mergeInsertionSortVector(void);

		static void		printVector(std::vector<int> v);
		static void		printList(std::list<int> l);

		static bool	isOnlyPos(char** av, int ac);

	private:

		std::vector<int>	_arr;
		std::list<int>		_list;
};

#endif
