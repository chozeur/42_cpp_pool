/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:56:59 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:32:05 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"


Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_val = val << this->_nbit;
	return ;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_val = (int)roundf(val * (1 << this->_nbit));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_val = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(const int raw)
{
	this->_val = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_val / (1 << this->_nbit));
}

int	Fixed::toInt(void) const
{
	return (this->_val >> this->_nbit);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &itm)
{
	out << itm.toFloat();
	return (out);
}
