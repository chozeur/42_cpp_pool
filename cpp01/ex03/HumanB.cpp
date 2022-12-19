/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:31:09 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/11 17:43:37 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

void	HumanB::attack(void) const
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType()
		<< std::endl;
	return ;
}

bool	HumanB::setWeapon(Weapon *weapon)
{
	this->_weapon = weapon;
	return (true);
}

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}
