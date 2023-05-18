#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

class	PmergeMe {

	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe(int ac, char **av);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &rhs);

		void		mergeInsertionSortVector(void);
		void		mergeInsertionSortList(void);

		void		printVector(void) const;
		void		printList(void) const;

		static bool	isOnlyDigits(char** av, int ac);

	private:

		std::vector<int>	_arr;
		std::list<int>		_list;
};

#endif
