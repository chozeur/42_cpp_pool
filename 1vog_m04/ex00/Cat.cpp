/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:41:01 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:09:43 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat(void) : Animal::Animal("Cat")
{
	std::cout << "Cat " << DFT << std::endl;
	return ;
}

Cat::Cat(const Cat &src) : Animal::Animal(src)
{
	std::cout << "Cat " << CPY << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat DESTRUCTOR CALLED" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAOU" << std::endl;
	return ;
}
