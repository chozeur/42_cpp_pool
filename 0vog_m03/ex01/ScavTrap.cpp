/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:40:29 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:42:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

//	CONSTRUCTORS & DESTRUCTORS
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap constructor by default called [" << this->_name << "]"
		<< std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor from std::string called [" << this->_name << "]"
		<< std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap constructor by copy called [" << this->_name << "]"
		<< std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called [" << this->_name << "]"
		<< std::endl;
	return ;
}

//	OPERATORS OVERLOAD
ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	ClapTrap::operator=(src);
	return (*this);
}

//	MEMBER FUNCTIONS
void	ScavTrap::attack(const std::string &target)
{
	if (this->_ep)
	{
		std::cout << this->_name << " is bullying " << target << ", causing "
			<< this->_ad << " points of damage !" << std::endl;
		this->_ep--;	//	attack costs 1 EP
	}
	else
		std::cout << this->_name << " has not enough EP to attack..." << std::endl;
	return ;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << this->_name << " entered Gate keeper mode" << std::endl;
	return ;
}
