/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:32:44 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/29 19:35:35 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"

//	CONSTRUCTORS & DESTRUCTORS
WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal " << DFT << std::endl;
	this->_type = "JUST AN ANIMAL";
	return ;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal CONSTRUCTOR FROM std::string CALLED" << std::endl;
	this->_type = type;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal " << CPY << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal DESTRUCTOR CALLED" << std::endl;
	return ;
}

//	OPERATORS OVERLOAD
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);

}

//	ACCESORS
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
	return ;
}

//	MEMBER FUNCTIONS
void	WrongAnimal::makeSound(void) const
{
	std::cout << "MUTE (noType WrongAnimal)" << std::endl;
	return ;
}

