/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:31 by alambert          #+#    #+#             */
/*   Updated: 2023/06/12 16:06:17 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

vectorMIS::vectorMIS(void)	{return ;}

vectorMIS::vectorMIS(vectorMIS const & toCopy) : _timeS(toCopy._timeS), _timeE(toCopy._timeE)	{
	std::copy(toCopy._vec.begin(), toCopy._vec.end(), _vec.begin());
}

vectorMIS::~vectorMIS(void)	{return ;}

listMIS::listMIS(void)	{return ;}

listMIS::listMIS(listMIS const & toCopy) : _timeS(toCopy._timeS), _timeE(toCopy._timeE)	{
	std::copy(toCopy._lst.begin(), toCopy._lst.end(), _lst.begin());
}

listMIS::~listMIS(void)	{return ;}

listMIS			&listMIS::operator=(listMIS const & toCopy)	{
	this->_timeS = toCopy._timeS;
	this->_timeE = toCopy._timeE;
	std::copy(toCopy._lst.begin(), toCopy._lst.end(), _lst.begin());
	return (*this);
}

vectorMIS		&vectorMIS::operator=(vectorMIS const & toCopy)	{
	this->_timeS = toCopy._timeS;
	this->_timeE = toCopy._timeE;
	std::copy(toCopy._vec.begin(), toCopy._vec.end(), _vec.begin());
	return (*this);
}

std::list<int>		&listMIS::getL(void) {return (_lst);}

std::vector<int>	&vectorMIS::getV(void)	{return (_vec);}

void	vectorMIS::vMerge(std::vector<std::pair<int, int> >& arr, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right) {
	unsigned long i = 0, j = 0, k = 0;
	unsigned long leftSize = left.size();
	unsigned long rightSize = right.size();

	while (i < leftSize && j < rightSize) {
		if (left[i].second <= right[j].second) {
			arr[k] = left[i];
			i++;
		}
		else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < leftSize) {
		arr[k] = left[i];
		i++;
		k++;
	}

	while (j < rightSize) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void	vectorMIS::vPairsMerge(std::vector<std::pair<int, int> >& arr) {
	unsigned long size = arr.size();
	if (size < 2)
		return ;

	unsigned long mid = size / 2;

	std::vector<std::pair<int, int> > left(arr.begin(), arr.begin() + mid);
	std::vector<std::pair<int, int> > right(arr.begin() + mid, arr.end());

	this->vPairsMerge(left);
	this->vPairsMerge(right);
	this->vMerge(arr, left, right);
}

int		vectorMIS::vBinarySearch(const std::vector<int>& arr, int low, int high, int target) {
	if (low > high) {
		return (low);
	}

	int mid = low + (high - low) / 2;

	if (arr[mid] == target)
		return (mid);
	else if (target > arr[mid])
		return (vBinarySearch(arr, mid + 1, high, target));
	else
		return (vBinarySearch(arr, low, mid - 1, target));
}

void	vectorMIS::vImplMIS(void) {
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> pendingValues;
	std::vector<int> mainChain;

	unsigned long size = this->getV().size();
	unsigned long i;

	for (i = 0; i < size - 1; i += 2) {
		pairs.push_back(std::make_pair(this->getV()[i], this->getV()[i + 1]));
	}

	int pendingValue = -1;
	if (size % 2 != 0) {
		pendingValue = this->getV()[size - 1];
	}

	for (i = 0; i < pairs.size(); i++) {
		if (pairs[i].first > pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
	}

	this->vPairsMerge(pairs);

	for (i = 0; i < pairs.size(); i++) {
		pendingValues.push_back(pairs[i].first);
	}

	if (pendingValue != -1) {
		pendingValues.push_back(pendingValue);
	}

	if (!pairs.empty()) {
		mainChain.push_back(pairs[0].first);
	}


	for (i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].second);
	}

	unsigned long pendingSize = pendingValues.size();
	unsigned long jacobsthal[pendingSize];

	jacobsthal[0] = 2;
	jacobsthal[1] = 2;

	for (i = 2; i <= pendingSize; i++) {
		jacobsthal[i] = jacobsthal[(i - 1)] + (jacobsthal[(i - 2)] * 2);

		if (jacobsthal[i]  > pendingSize)	{

			break;
		}
	}

	for (i = 1; jacobsthal[i - 1] <= pendingSize; i++) {
		int insertIndex;
		if (jacobsthal[i] - jacobsthal[i - 1] < 2) {
			insertIndex = vBinarySearch(mainChain, 0, mainChain.size() - 1, pendingValues[jacobsthal[i]]);
			mainChain.insert(mainChain.begin() + insertIndex, pendingValues[jacobsthal[i]]);
		}
		else {
			if (jacobsthal[i] < pendingSize) {
				insertIndex = vBinarySearch(mainChain, 0, mainChain.size() - 1, pendingValues[jacobsthal[i]]);
				mainChain.insert(mainChain.begin() + insertIndex, pendingValues[jacobsthal[i]]);
				for (unsigned long j = (jacobsthal[i] - 1); j > jacobsthal[i - 1]; j--)	{
					insertIndex = vBinarySearch(mainChain, 0, mainChain.size() - 1, pendingValues[j]);
					mainChain.insert(mainChain.begin() + insertIndex, pendingValues[j]);
				}
			}
			else {
				for (unsigned long j = pendingSize - 1; j > jacobsthal[i - 1]; j--) {
					insertIndex = vBinarySearch(mainChain, 0, mainChain.size() - 1, pendingValues[j]);
					mainChain.insert(mainChain.begin() + insertIndex, pendingValues[j]);
				}
			}
		}
	}
	this->_timeE = clock();

	std::cout << BOLD << GREEN << "Vector sorted sequence: " << RESET;
	for (i = 0; i < mainChain.size(); i++) {
		std::cout << mainChain[i] << " ";
	}
	std::cout << RESET << FORMAT_RESET << std::endl;
}

void	vectorMIS::vMIS(int argc, char ** argv)	{
	_timeS = clock();

	if (!checkInput(argc, argv))	{
		throw (std::invalid_argument("Invalid argument input: only digits required."));
		return ;
	}

	this->getV().reserve(argc - 1);
	std::transform(argv + 1, argv + argc, std::back_inserter(_vec), std::atoi);

	if (this->getV().empty() != 0 || this->getV().size() != static_cast<unsigned long>(argc -1))
		throw (std::invalid_argument("vectorMIS: Invalid argument input: vector push_back issue"));

	this->vImplMIS();

	std::cout << std::endl;
	std::cout << "vector took: " << std::setprecision(10) << (((double)(_timeE - _timeS) / CLOCKS_PER_SEC) / (1e-6)) << " μs.\n\n";
}


void	listMIS::lMerge(std::list<std::pair<int, int> >& arr, std::list<std::pair<int, int> >& left, std::list<std::pair<int, int> >& right) {
	std::list<std::pair<int, int> >::iterator it_left = left.begin();
	std::list<std::pair<int, int> >::iterator it_right = right.begin();

	while (it_left != left.end() && it_right != right.end()) {
		if (it_left->second <= it_right->second) {
			arr.push_back(*it_left);
			++it_left;
		} else {
			arr.push_back(*it_right);
			++it_right;
		}
	}

	while (it_left != left.end()) {
		arr.push_back(*it_left);
		++it_left;
	}

	while (it_right != right.end()) {
		arr.push_back(*it_right);
		++it_right;
	}
}

void	listMIS::lPairsMerge(std::list<std::pair<int, int> >& arr) {
	std::list<std::pair<int, int> >::size_type size = arr.size();
	if (size < 2) {
		return ;
	}

	std::list<std::pair<int, int> > left, right;

	std::list<std::pair<int, int> >::iterator it = arr.begin();
	std::advance(it, size / 2);
	left.splice(left.begin(), arr, arr.begin(), it);
	right.splice(right.begin(), arr, it, arr.end());

	this->lPairsMerge(left);
	this->lPairsMerge(right);
	this->lMerge(arr, left, right);
}

bool	listMIS::isLeftOf(std::list<int>::iterator it1, std::list<int>::iterator it2, const std::list<int>& lst)		{
	std::list<int>::const_iterator it = lst.begin();
	while (it!= lst.end()) {
		if (it == it1 && it1 != it2)
			return (true);
		else if (it == it2)
			return (false);
		++it;
	}
	return (false);
}

std::list<int>::iterator	listMIS::lBinarySearch(const std::list<int>& arr, std::list<int>::iterator low, std::list<int>::iterator high, int target) {
	if (isLeftOf(high, low, arr)) {
		return (low);
	}
	std::list<int>::iterator mid = low;
	int	tempS = std::distance(low, high) / 2;
	std::advance(mid, tempS);

	if (target == *mid) {
		return mid;
	} else if (target >= *mid) {
		return lBinarySearch(arr, ++mid, high, target);
	} else {
		return lBinarySearch(arr, low, --mid, target);
	}
}

void 	listMIS::lImplMIS(void) {
	std::list<std::pair<int, int> > pairs;
	std::list<int> pendingValues;
	std::list<int> mainChain;

	std::list<int>::size_type size = getL().size();
	std::list<int>::iterator it = getL().begin();

	while (std::distance(it, getL().end()) >= 2) {
		pairs.push_back(std::make_pair(*it, *(++it)));
		++it;
	}

	int pendingValue = -1;
	if (size % 2 != 0) {
		pendingValue = getL().back();
	}

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first > it->second) {
			std::swap(it->first, it->second);
		}
	}

	this->lPairsMerge(pairs);

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		pendingValues.push_back(it->first);
	}

	if (pendingValue != -1) {
		pendingValues.push_back(pendingValue);
	}

	if (!pairs.empty()) {
		mainChain.push_back(pairs.front().first);
	}

	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		mainChain.push_back(it->second);
	}

	unsigned long pendingSize = pendingValues.size();
	unsigned long i;
	std::list<int>::iterator low = mainChain.begin();
	std::list<int>::iterator high = low;
	std::advance(high, (mainChain.size() - 1));
	std::list<int>::iterator start = pendingValues.begin();

	for (i = 1; i < pendingSize; i++) {
			std::list<int>::iterator insertIndex;
			std::list<int>::iterator scopy = start;
			std::advance(scopy, i);

			if (*scopy < *low) {
				mainChain.insert(low, *scopy);
				low = mainChain.begin();
			} else if (*scopy > *low)	{
				insertIndex = lBinarySearch(mainChain, low, high, *scopy);
				mainChain.insert(insertIndex, *scopy);
			}
	}
	this->_timeE = clock();

	std::cout << BOLD << BLUE << "List sorted sequence: " << RESET;
	for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << RESET << FORMAT_RESET << std::endl;
}

void	listMIS::lMIS(int argc, char ** argv)	{
	this->_timeS = clock();
	if (!checkInput(argc, argv)) {
		throw (std::invalid_argument("Invalid argument input: only digits required."));
		return ;
	} else {
		std::transform(argv + 1, argv + argc, std::back_inserter(_lst), std::atoi);
		if (this->getL().empty() != 0 || this->getL().size() != static_cast<unsigned long>(argc -1))
			throw (std::invalid_argument("vectorMIS: Invalid argument input: vector push_back issue"));
		this->lImplMIS();
		std::cout << std::endl;
		std::cout << "list took: " << std::setprecision(10) << (((double)(this->_timeE - this->_timeS) / CLOCKS_PER_SEC) / (1e-6)) << " μs.\n\n";
	}
}

bool		checkInput(int argc, char ** argv) {
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j] != '\0'; j++)
			if (!std::isdigit(argv[i][j]))
				return (0);

	return (1);
}
