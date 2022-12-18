/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:26 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("Joe", 5);
	Bureaucrat	b("Bill", 145);
	Bureaucrat	c("Paul", 151);
	Bureaucrat	d("Peter", 0);

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Bureaucrat " << a << " is going to be upgraded..." << std::endl;
		try
		{
			a.increaseGrade();
		}
		catch (std::exception &e)
		{
			std::cout << a.getName() << "'s " << e.what() << std::endl;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Bureaucrat " << b << " is going to be downgraded..." << std::endl;
		try
		{
			b.decreaseGrade();
		}
		catch (std::exception &e)
		{
			std::cout << b.getName() << "'s " << e.what() << std::endl;
		}
	}

	return (0);
}
