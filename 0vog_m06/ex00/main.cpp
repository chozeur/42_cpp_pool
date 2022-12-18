/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:33:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/17 15:35:35 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConversion.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error in arguments" << std::endl;
		return (1);
	}

	std::string	input(av[1]);
	ScalarConversion	a(input);

	std::cout << "char : ";
	try {
		a.getChar();
		std::cout << '\'' << a.getChar() << '\'' << std::endl;
	} catch (ScalarConversion::conversionImpossibleException &e) {
		std::cout << e.what() << std::endl;
	} catch (ScalarConversion::conversionNonDisplayableException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "int : ";
	try {
		std::cout << a.getInt() << std::endl;
	} catch (ScalarConversion::conversionImpossibleException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "float : " << std::fixed << std::setprecision(1) << a.getFloat() << 'f' << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << a.getDouble() << std::endl;

	return (0);
}
