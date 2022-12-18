/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:32:47 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/29 19:37:36 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout << "WrongCat " << DFT << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal::WrongAnimal(src)
{
	std::cout << "WrongCat " << CPY << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat DESTRUCTOR CALLED" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MIAOU" << std::endl;
	return ;
}
