/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:53 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:41:06 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

//	CONSTRUCTORS & DESTRUCTOR
ClapTrap::ClapTrap(void): _name("NO_NAME_GIVEN"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Constructor by default called [" << this->_name << "]" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "Constructor from std::string called [" << this->_name << "]" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Constructor by copy called [" << this->_name << "]" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called [" << this->_name << "]" << std::endl;
	return ;
}

//	OPERATORS OVERLOAD
ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hp = src.getHp();
		this->_ep = src.getEp();
		this->_ad = src.getAd();
	}
	return (*this);
}

//	SETERS & ACCESSORS
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
	return ;
}

int			ClapTrap::getHp(void) const
{
	return (this->_hp);
}

void		ClapTrap::setHp(int hp)
{
	this->_hp = hp;
	return ;
}

int			ClapTrap::getEp(void) const
{
	return (this->_ep);
}

void		ClapTrap::setEp(int ep)
{
	this->_ep = ep;
	return ;
}

int			ClapTrap::getAd(void) const
{
	return (this->_ad);
}

void		ClapTrap::setAd(int ad)
{
	this->_ad = ad;
	return ;
}

//	MEMBER FUNCTIONS
void		ClapTrap::attack(const std::string &target)
{
	if (this->_ep)
	{
		std::cout << this->_name << " attacks " << target << ", causing "
			<< this->_ad << " points of damage !" << std::endl;
		this->_ep--;	//	attack costs 1 EP
	}
	else
		std::cout << this->_name << " has not enough EP to attack..." << std::endl;
	return ;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	if (this->_hp > 0)
	{
	std::cout << this->_name << " lost " << amount << " HP, he has now "
		<< this->_hp << std::endl;
	}
	else
	{
		this->_hp = 0;
		std::cout << this->_name << " is dead..."
			<< std::endl;
	}
	return ;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep)
	{
		std::cout << this->_name << " is being repaired by " << amount;
		this->_ep--;	//	repair costs 1 EP
		this->_hp += amount;
		std::cout << " , he has now " << this->_hp << std::endl;
	}
	else
		std::cout << this->_name << " has not enough EP to repair..." << std::endl;
	return ;
}

