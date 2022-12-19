/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:56:59 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 21:33:05 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

//	CONSTRUCTEURS & DESTRUCTEUR
Fixed::Fixed(void)
{
	this->_val = 0;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int val)
{
	this->_val = val << this->_nbit;
	return ;
}

Fixed::Fixed(const float val)
{
	this->_val = (int)roundf(val * (1 << this->_nbit));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

//	SURCHARGES D'OPERATEUR
Fixed	&Fixed::operator=(const Fixed &right)
{
	if (this != &right)
		this->_val = right.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &right)
{
	if (this->_val > right._val)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &right)
{
	if (this->_val < right._val)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &right)
{
	if (this->_val >= right._val)
		return (true);
	return (false);

}

bool	Fixed::operator<=(const Fixed &right)
{
	if (this->_val <= right._val)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &right)
{
	if (this->_val == right._val)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &right)
{
	if (this->_val != right._val)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &right)
{
	return (Fixed((this->_val + right.getRawBits()) / (float)256));
}

Fixed	Fixed::operator-(const Fixed &right)
{
	return (Fixed((this->_val - right.getRawBits()) / (float)256));
}

Fixed	Fixed::operator*(const Fixed &right)
{
	Fixed	tmp;

	tmp.setRawBits((this->_val * right.getRawBits()) / (float)256);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &right)
{
	Fixed	tmp;

	if (!this->_val)
		return (Fixed(0));
	tmp.setRawBits((this->_val / right.getRawBits()) * (float)256);
	return (tmp);
}

Fixed	&Fixed::operator++()
{
	++(this->_val);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	--(this->_val);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	--(*this);
	return (tmp);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &itm)
{
	out << itm.toFloat();
	return (out);
}

//	ACCESSEURS
int	Fixed::getRawBits(void) const
{
	return (this->_val);
}

void	Fixed::setRawBits(const int raw)
{
	this->_val = raw;
	return ;
}

//	FONCTIONS MEMBRES
float	Fixed::toFloat(void) const
{
	return ((float)this->_val / (1 << this->_nbit));
}

int	Fixed::toInt(void) const
{
	return (this->_val >> this->_nbit);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if ((Fixed)a < (Fixed)b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if ((Fixed)a > (Fixed)b)
		return (a);
	return (b);
}
