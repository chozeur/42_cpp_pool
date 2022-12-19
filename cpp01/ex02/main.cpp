/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:53:05 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/21 18:13:47 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::endl
		<< "ADDRESSES"
		<< std::endl << std::endl
		<< "\tstring    -> " << &string
		<< std::endl << std::endl
		<< "\tstringPTR -> " << stringPTR
		<< std::endl << std::endl
		<< "\tstringREF -> " << &stringREF
		<< std::endl << std::endl
		<< "VALUES"
		<< std::endl << std::endl
		<< "\tstring    -> " << string
		<< std::endl << std::endl
		<< "\tstringPTR -> " << *stringPTR
		<< std::endl << std::endl
		<< "\tstringREF -> " << stringREF
		<< std::endl << std::endl;
	return (0);
}
