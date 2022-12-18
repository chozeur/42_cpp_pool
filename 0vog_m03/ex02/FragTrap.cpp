/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:16:34 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:42:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

//	CONSTRUCTORS & DESTRUCTORS
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap constructor by default called ["
		<< this->_name << "]" << std::endl;
	this->_ep = 100;
	this->_ad = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor from std::string called ["
		<< this->_name << "]" << std::endl;
	this->_ep = 100;
	this->_ad = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap constructor by copy called [" << this->_name
		<< "]" << std::endl;
	this->_ep = 100;
	this->_ad = 30;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap default destructor called [" << this->_name << "]"
		<< std::endl;
	return ;
}

//	OPERATORS OVERLOAD
FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	ClapTrap::operator=(src);
	return (*this);
}

//	MEMBER FUNCTIONS
void		FragTrap::highFiveGuys(void) const
{
	std::cout << "It's " << this->_name << ", give me a high five !" << std::endl;
	return ;
}
