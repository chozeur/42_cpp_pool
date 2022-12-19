/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:34:35 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 19:01:41 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# include "./Span.hpp"
#endif

#include <vector>

int	main(void)
{
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		sp.addNumber(42);	//	MUST THROW AN EXCEPTION AS sp IS ALREADY FULL
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "span size is <= 1" << std::endl;
	}

	std::cout << std::endl << std::endl;
}
{
	Span	sp(42);

	try {
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "span size is <= 1" << std::endl;
	}
	
	std::cout << std::endl << std::endl;
}
{
	std::vector<int> vec;
	Span	sp(10000);

	for(int i = 0; i < 10000; i++)
		vec.push_back(i);
	sp.fillRange<std::vector<int> >(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
	return (0);
}
