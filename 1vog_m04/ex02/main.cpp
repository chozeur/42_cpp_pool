/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:10:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:58:46 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

# define TEST 42

int	main(void)
{
	AAnimal	*tab[TEST];

	for (int i = 0; i < TEST; i++)
	{
		if (i % 2)
			tab[i] = new Cat();
		else
			tab[i] = new Dog();
	}

	for (int i = 0; i < TEST; i++)
		delete tab[i];

	return (0);
}
