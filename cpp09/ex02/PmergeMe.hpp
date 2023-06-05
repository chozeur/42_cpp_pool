/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:31 by alambert          #+#    #+#             */
/*   Updated: 2023/05/31 19:19:52 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

// Libraries **************************************************************** //
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

// **************************************************************** Libraries //



// Colours ****************************************************************** //
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[33m"
#define MAGENTA "\e[35m"
#define CLEAR "\e[0m"
// ****************************************************************** Colours //


// Enums ******************************************************************** //
// ******************************************************************** Enums //


// Templates **************************************************************** //
// **************************************************************** Templates //

// Structs ****************************************************************** //
// ****************************************************************** Structs //

// Classes ****************************************************************** //

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
	clock_t							_timeS;				// time start
	clock_t							_timeE;				// time end
};

class listMIS	{
public:
	listMIS(void);										// Canonical
	listMIS(listMIS const & toCopy);					// Canonical
	~listMIS(void);										// Canonical

	listMIS	&operator=(listMIS const & toCopy);			// Canonical

	std::list<int>			 		&getL(void);
	void							lMIS(int argc, char ** argv);
	void							lImplMIS(void);
	void							lMerge(std::list<std::pair<int, int> >& arr, std::list<std::pair<int, int> >& left, std::list<std::pair<int, int> >& right);
	void							lPairsMerge(std::list<std::pair<int, int> >& arr);
	bool 							isLeftOf(std::list<int>::iterator it1, std::list<int>::iterator it2, const std::list<int>& lst);
	std::list<int>::iterator 		lBinarySearch(const std::list<int>& arr, std::list<int>::iterator low, std::list<int>::iterator high, int target);

private:
	std::list<int>					_lst;
	clock_t							_timeS;				// time start
	clock_t							_timeE;				// time end
};
// ****************************************************************** Classes //


// Non Member functions ***************************************************** //
bool			checkInput(int argc, char ** argv);
// ***************************************************** Non Member functions //

#endif // ******************************************************** PMERGEME_H //