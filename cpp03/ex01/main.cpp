/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:45 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:42:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int	main(void)
{
	ClapTrap	ca("Joe");
	ScavTrap	sa("Paul");
	std::cout << std::endl;

	ca.attack(sa.getName());
	sa.takeDamage(ca.getAd());
	std::cout << std::endl;

	sa.attack(ca.getName());
	ca.takeDamage(sa.getAd());
	std::cout << std::endl;

	sa.guardGate();
	std::cout << std::endl;

	ScavTrap	sb(sa);
	sb.setName("Clone");
	sb.attack(ca.getName());
	ca.takeDamage(sb.getAd());
	std::cout << std::endl;

	sb.guardGate();
	std::cout << std::endl;

	return (0);
}

