#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {return ;}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
	return ;
}

PmergeMe::PmergeMe(int ac, char **av) {
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

void PmergeMe::mergeInsertionSortVector(void) {
	const int n = _arr.size();
	const int k = 5; // set the threshold for switching to insertion sort

	// perform insertion sort on small sub_arrays
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j > 0 && _arr[j] < _arr[j - 1]) {
			std::swap(_arr[j], _arr[j - 1]);
			--j;
		}
	}

	// perform merge sort on larger sub_arrays
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
				if (_arr[j] <= _arr[k]) {
					tmp[idx] = _arr[j];
					++j;
				} else {
					tmp[idx] = _arr[k];
					++k;
				}
				++idx;
			}
			while (j < m) {
				tmp[idx] = _arr[j];
				++j;
				++idx;
			}
			while (k < r) {
				tmp[idx] = _arr[k];
				++k;
				++idx;
			}
			std::copy(tmp.begin(), tmp.end(), _arr.begin() + l);
		}
	}
}

