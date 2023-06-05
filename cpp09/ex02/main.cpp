/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:34:46 by alambert          #+#    #+#             */
/*   Updated: 2023/05/31 19:29:53 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printArgs(int argc, char ** argv)	{
	checkInput(argc, argv);
	std::cout << std::endl;
	std::cout << "// Args ===================================================================== //" << std::endl;
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl << std::endl;
}

int	main(int argc, char ** argv)	{
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
