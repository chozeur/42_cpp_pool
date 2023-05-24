#include "tstPmergeMe.hpp"

PmergeMe::PmergeMe(void) {return ;}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
	return ;
}

PmergeMe::PmergeMe(int ac, char **av) {
	if (ac < 2) {
		std::cout << RED << "Usage: ./PmergeMe [positive integers]" << RESET << std::endl;
		exit(42);
	} else if (!isOnlyPos(av, ac)) {
		std::cout << RED << "Usage: ./PmergeMe [positive integers]" << RESET << std::endl;
		exit(42);
	}

	for (int i = 1; i < ac; ++i){
		_arr.push_back(atoi(av[i]));
		_list.push_back(atoi(av[i]));
	}
	return ;
}

PmergeMe::~PmergeMe(void) {return ;}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		_arr = rhs._arr;
		_list = rhs._list;
	}
	return *this;
}

std::vector<int>	PmergeMe::getVector(void) const {return _arr;}

std::list<int>	PmergeMe::getList(void) const {return _list;}

void	PmergeMe::mergeInsertionSortVector(void){
	
}

void	PmergeMe::printVector(std::vector<int> v) {
	for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printList(std::list<int> l) {
	for (std::list<int>::const_iterator i = l.begin(); i != l.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

bool	PmergeMe::isOnlyPos(char** av, int ac) {
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (!isdigit(av[i][j])) {
				return false;
			}
		}
	}
	for (int i = 1; i < ac; ++i) {
		if (atoi(av[i]) <= 0) {
			return false;
		}
	}
	return true;
}
