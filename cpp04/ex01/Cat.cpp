/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:41:01 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 15:17:30 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat(void) : Animal::Animal("Cat")
{
	std::cout << "Cat " << DFT << std::endl;
	this->_brain = new Brain();
	return ;
}

Cat::Cat(const Cat &src) : Animal::Animal(src), _brain(new Brain(*(src._brain)))
{
	std::cout << "Cat " << CPY << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat DESTRUCTOR CALLED" << std::endl;
	delete this->_brain;
	return ;
}

Cat	&Cat::operator=(const Cat &src)
{
	delete this->_brain;
	this->_brain = new Brain(*(src._brain));
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAOU" << std::endl;
	return ;
}

void	Cat::extractIdeas(void)
{
	for (int i = 0; i < 100; ++i)
		std::cout << this->_brain->extractIdea(i) << std::endl;
	return ;
}
