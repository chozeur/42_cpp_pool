/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:10:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 15:20:55 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

# define TEST 8

int	main(void)
{
	Animal	*tab[TEST];

	for (int i = 0; i < TEST; i++)
	{
		if (i % 2)
			tab[i] = new Cat();
		else
			tab[i] = new Dog();
	}

	Dog	dogB;

	{
		Dog	dogA = Dog();
		std::cout << "Ideas of dogA :" << std::endl; dogA.extractIdeas();
		dogB = dogA;
	}
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "dogA has been deleted" << std::endl;
	std::cout << "Ideas of dogB :" << std::endl; dogB.extractIdeas();

	for (int i = 0; i < TEST; i++)
		delete tab[i];
	return (0);
}
