/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:46 by alambert          #+#    #+#             */
/*   Updated: 2023/06/12 15:53:42 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printArgs(int argc, char ** argv)	{
	checkInput(argc, argv);
	std::cout << BOLD << YELLOW << "Numbers to sort:" << RESET << FORMAT_RESET << std::endl;
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl << std::endl;
}

int	main(int argc, char ** argv)	{

	system("clear");

	if (argc < 2)	{
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	printArgs(argc, argv);

	vectorMIS	vec;
	listMIS		lst;

	try	{
		lst.lMIS(argc, argv);
	}
	catch(const std::exception& e)	{
		std::cerr << "List: Error: " << e.what() << '\n';
		return 1;
	}

	try	{
		vec.vMIS(argc, argv);
	}
	catch(const std::exception& e)	{
		std::cerr << "Vector: Error: " << e.what() << '\n';
		return 1;
	}

	return (0);
}
