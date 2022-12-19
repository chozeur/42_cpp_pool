/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:56:55 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:08:42 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog(void) : Animal::Animal("Dog")
{
	std::cout << "Dog " << DFT << std::endl;
	return ;
}

Dog::Dog(const Dog &src) : Animal::Animal(src)
{
	std::cout << "Dog " << CPY << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog DESTRUCTOR CALLED" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF" << std::endl;
	return ;
}
