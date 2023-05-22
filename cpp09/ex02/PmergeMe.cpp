#include "PmergeMe.hpp"

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

std::vector<int>	PmergeMe::mergeInsertionSortVector(void) {
	std::vector<int>	res = _arr;

	const int n = res.size();
	const int k = 5; // set the threshold for switching to insertion sort

	// perform insertion sort on small subarrays
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0 && res[j] < res[j - 1]) {
			std::swap(res[j], res[j - 1]);
			--j;
		}
	}

	// perform merge sort on larger subarrays
	for (int s = k; s < n; s *= 2) {
		for (int i = 0; i < n; i += 2 * s) {
			int l = i;
			int m = std::min(i + s, n);
			int r = std::min(i + 2 * s, n);
			std::vector<int> tmp(r - l);
			int idx = 0;
			int j = l;
			int k = m;
			while (j < m && k < r) {
				if (res[j] <= res[k]) {
					tmp[idx] = res[j];
					++j;
				} else {
					tmp[idx] = res[k];
					++k;
				}
				++idx;
			}
			while (j < m) {
				tmp[idx] = res[j];
				++j;
				++idx;
			}
			while (k < r) {
				tmp[idx] = res[k];
				++k;
				++idx;
			}
			std::copy(tmp.begin(), tmp.end(), res.begin() + l);
		}
	}
	return (res);
}

std::list<int>	PmergeMe::mergeSortedList(std::list<int> a, std::list<int> b) {
	std::list<int> result;
	while (!a.empty() && !b.empty()) {
		if (a.front() < b.front()) {
			result.push_back(a.front());
			a.pop_front();
		} else {
			result.push_back(b.front());
			b.pop_front();
		}
	}
	while (!a.empty()) {
		result.push_back(a.front());
		a.pop_front();
	}
	while (!b.empty()) {
		result.push_back(b.front());
		b.pop_front();
	}
	return result;
}

std::list<int> PmergeMe::insertionSortList(std::list<int> arr) {
	for (std::list<int>::iterator i = arr.begin(); i != arr.end(); i++) {
		std::list<int>::iterator j = i;
		while (j != arr.begin() && *j < *--j) {
			std::iter_swap(j, j++);
		}
	}
	return arr;
}

std::list<int>	PmergeMe::mergeInsertionSortList(std::list<int>& arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	std::list<int>::iterator middle = arr.begin();
	std::advance(middle, arr.size() / 2);
	std::list<int> left(arr.begin(), middle);
	std::list<int> right(middle, arr.end());
	left = insertionSortList(left);
	right = insertionSortList(right);
	return mergeSortedList(left, right);
}

void	PmergeMe::printVector(std::vector<int> v) {
	for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printList(std::list<int>l ) {
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
