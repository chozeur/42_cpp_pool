/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:11:50 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/15 14:03:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ex04.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << std::endl << std::endl
			<< "Use as : ./Sed_is_for_losers <file_path> <s1> <s2>"
			<< std::endl << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	File	fileIn((std::string)av[1], READ);
	if (!fileIn.read_file())
	{
		std::cerr << std::endl << std::endl
			<< "error : '" << av[1] << "' can't be opened"
			<< std::endl << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	if (fileIn.get_fileStr().empty())
	{
		std::cerr << std::endl << std::endl
			<< "error : '" << av[1] << "' is empty"
			<< std::endl << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	File	fileOut(((std::string)av[1]).append(".replace"), WRITE);
	fileOut.write_file(sed_str(fileIn.get_fileStr(),
		(std::string)av[2], (std::string)av[3]));
	return (0);
}
