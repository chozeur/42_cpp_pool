/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:56:55 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 15:17:36 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog(void) : Animal::Animal("Dog")
{
	std::cout << "Dog " << DFT << std::endl;
	this->_brain = new Brain();
	return ;
}

Dog::Dog(const Dog &src) : Animal::Animal(src), _brain(new Brain(*(src._brain)))
{
	std::cout << "Dog " << CPY << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog DESTRUCTOR CALLED" << std::endl;
	delete this->_brain;
	return ;
}

Dog	&Dog::operator=(const Dog &src)
{
	delete this->_brain;
	this->_brain = new Brain(*(src._brain));
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "WOOF" << std::endl;
	return ;
}

void	Dog::extractIdeas(void)
{
	for (int i = 0; i < 100; ++i)
		std::cout << this->_brain->extractIdea(i) << std::endl;
	return ;
}
