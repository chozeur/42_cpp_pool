/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:31 by alambert          #+#    #+#             */
/*   Updated: 2023/06/05 15:25:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <iostream>
#include <iomanip>
#include <functional>
#include <ctime>
#include <list>
#include <vector>
#include <sstream>
#include <cmath>
#include <iterator>
#include <exception>
#include <algorithm>
#include <cstddef>

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

class vectorMIS	{
	public:
	vectorMIS(void);									// Canonical
	vectorMIS(vectorMIS const & toCopy);				// Canonical
	~vectorMIS(void);									// Canonical

	vectorMIS	&operator=(vectorMIS const & toCopy);	// Canonical

	std::vector<int> 				&getV(void);
	void							vMIS(int argc, char ** argv);
	void							vImplMIS(void);
	void 							vMerge(std::vector<std::pair<int, int> >& arr, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right);
	void							vPairsMerge(std::vector<std::pair<int, int> >& arr);
	int 							vBinarySearch(const std::vector<int>& arr, int low, int high, int target);

private:
	std::vector<int> 		_vec;
	clock_t							_timeS;
	clock_t							_timeE;
};

class listMIS	{
public:
	listMIS(void);
	listMIS(listMIS const & toCopy);
	~listMIS(void);

	listMIS	&operator=(listMIS const & toCopy);

	std::list<int>			 		&getL(void);
	void							lMIS(int argc, char ** argv);
	void							lImplMIS(void);
	void							lMerge(std::list<std::pair<int, int> >& arr, std::list<std::pair<int, int> >& left, std::list<std::pair<int, int> >& right);
	void							lPairsMerge(std::list<std::pair<int, int> >& arr);
	bool 							isLeftOf(std::list<int>::iterator it1, std::list<int>::iterator it2, const std::list<int>& lst);
	std::list<int>::iterator 		lBinarySearch(const std::list<int>& arr, std::list<int>::iterator low, std::list<int>::iterator high, int target);

private:
	std::list<int>					_lst;
	clock_t							_timeS;
	clock_t							_timeE;
};

bool			checkInput(int argc, char ** argv);

#endif
