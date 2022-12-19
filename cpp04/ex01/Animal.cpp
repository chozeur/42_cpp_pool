/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:28:07 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:58:46 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

//	CONSTRUCTORS & DESTRUCTORS
Animal::Animal(void)
{
	std::cout << "Animal " << DFT << std::endl;
	this->_type = "JUST AN ANIMAL";
	return ;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal CONSTRUCTOR FROM std::string CALLED" << std::endl;
	this->_type = type;
	return ;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal " << CPY << std::endl;
	*this = src;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal DESTRUCTOR CALLED" << std::endl;
	return ;
}

//	OPERATORS OVERLOAD
Animal	&Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);

}

//	ACCESORS
std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
	return ;
}

//	MEMBER FUNCTIONS
void	Animal::makeSound(void) const
{
	std::cout << "MUTE (noType Animal)" << std::endl;
	return ;
}
