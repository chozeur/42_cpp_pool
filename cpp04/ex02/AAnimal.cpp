/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:28:07 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/13 12:16:52 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

//	CONSTRUCTORS & DESTRUCTORS
AAnimal::AAnimal(void)
{
	std::cout << "AAnimal " << DFT << std::endl;
	this->_type = "JUST AN AAnimal";
	return ;
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal CONSTRUCTOR FROM std::string CALLED" << std::endl;
	this->_type = type;
	return ;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal " << CPY << std::endl;
	*this = src;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal DESTRUCTOR CALLED" << std::endl;
	return ;
}

//	OPERATORS OVERLOAD
AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);

}

//	MEMBER FUNCTIONS
void	AAnimal::makeSound(void) const
{
	std::cout << "MUTE (noType AAnimal)" << std::endl;
	return ;
}
