/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:17:08 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/12 12:26:18 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void) : _val(0)
{
	return ;
}

ScalarConversion::ScalarConversion(std::string str) : _val(atof(str.c_str()))
{
	return ;
}

ScalarConversion::ScalarConversion(const ScalarConversion &src)
{
	*this = src;
	return ;
}

ScalarConversion::~ScalarConversion(void)
{
	return ;
}

ScalarConversion	&ScalarConversion::operator=(const ScalarConversion &src)
{
	if (this != &src)
		this->_val = src._val;
	return (*this);
}

char	ScalarConversion::getChar(void) const
{
	try {
		if (this->_val < 0 || this->_val > 127 || isnan(this->_val))
			throw (conversionImpossibleException());
		else if (!std::isprint(static_cast<char>(this->_val)))
			throw (conversionNonDisplayableException());
	} catch (std::exception &e) {
		throw ;
	}
	return (static_cast<char>(this->_val));
}

int		ScalarConversion::getInt(void) const
{
	try {
		if (!std::isfinite(this->_val) || this->_val < INT_MIN || this->_val > INT_MAX)
			throw (conversionImpossibleException());
	} catch (std::exception &e) {
		throw ;
	}
	return (static_cast<int>(this->_val));
}

float	ScalarConversion::getFloat(void) const
{
	return (static_cast<float>(this->_val));
}

double	ScalarConversion::getDouble(void) const
{
	return (this->_val);
}
