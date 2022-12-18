/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:39:47 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/21 19:16:29 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie " << this->_name << " has been destroyed" \
		<< std::endl;
	return ;
}

std::string	Zombie::get_name(void) const
{
	return (this->_name);
}

bool	Zombie::set_name(std::string name)
{
	this->_name = name;
	return (true);
}

void	Zombie::announce(void) const
{
	std::cout << this->get_name() << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
