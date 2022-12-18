/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:44:23 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/12 18:18:16 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType(void) const
{
	const std::string	&typeRef = this->_type;
	return (typeRef);
}

bool	Weapon::setType(std::string type)
{
	this->_type = type;
	return (true);
}

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon constructor called" << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}
