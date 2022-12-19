/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:23:03 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/16 16:13:56 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int			N;
	std::string	name;
	Zombie		*horde;

beg:
	std::cout << std::endl << std::endl \
		<< "How many Zombies do you need ?" \
		<< std::endl << std::endl \
		<< "\t--> ";
	std::cin >> N;
	std::cout << std::endl << std::endl \
		<< "What will be their name ?" \
		<< std::endl << std::endl \
		<< "\t--> ";
	std::cin >> name;
	horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cerr << std::endl << "The hord must contain at least 1 zombie" << std::endl;
		goto beg;
	}
	std::cout << std::endl << std::endl \
		<< "The horde is here !" \
		<< std::endl << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	std::cout << std::endl << std::endl \
		<< "The horde will now be destroyed" \
		<< std::endl << std::endl;
	delete[] horde;
	return (0);
}
