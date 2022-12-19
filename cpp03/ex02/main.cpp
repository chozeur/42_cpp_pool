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
#include "./FragTrap.hpp"

int	main(void)
{
	ClapTrap	ca("Peter");
	ScavTrap	sa("Paolo");
	FragTrap	fa("Brips");
	std::cout << "--------------------------------" << std::endl;

	ClapTrap	cb(sa);
	cb.setName("Clone#1");
	std::cout << "--------------------------------" << std::endl;

	ScavTrap	sb(sa);
	sb.setName("Clone#2");
	std::cout << "--------------------------------" << std::endl;

	FragTrap	fb(fa);
	fb.setName("Clone#3");
	std::cout << "--------------------------------" << std::endl;

	ca.attack(fb.getName());
	fb.takeDamage(ca.getAd());
	std::cout << "--------------------------------" << std::endl;

	sa.attack(ca.getName());
	ca.takeDamage(sa.getAd());
	std::cout << "--------------------------------" << std::endl;

	fa.attack(sa.getName());
	sa.takeDamage(fa.getAd());
	std::cout << "--------------------------------" << std::endl;

	cb.attack(fa.getName());
	fa.takeDamage(cb.getAd());
	std::cout << "--------------------------------" << std::endl;

	sb.attack(cb.getName());
	cb.takeDamage(sb.getAd());
	std::cout << "--------------------------------" << std::endl;

	fb.attack(sb.getName());
	sb.takeDamage(fb.getAd());
	std::cout << "--------------------------------" << std::endl;

	return (0);
}

