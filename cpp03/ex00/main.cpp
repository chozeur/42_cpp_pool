/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:45 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:41:24 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a;
	ClapTrap	b("Clap1");

	a.setName("Clap0");

	b.attack(a.getName());
	a.takeDamage(b.getAd());
	a.beRepaired(5);

	/* std::cout << a.getName() << " has now 1 AD" << std::endl;
	a.setAd(1);

	for (int i = 0; i < 11; i++)
	{
		a.attack(b.getName());
		b.takeDamage(a.getAd());
	} */

	return (0);
}

