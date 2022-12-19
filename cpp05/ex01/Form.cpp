/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:48:30 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form(void) : _name("NO_NAME"), _signed(false), _toSign(1), _toExec(1)
{
	return ;
}

Form::Form(std::string name, const int toSign, const int toExec) : _name(name), _signed(false), _toSign(toSign), _toExec(toExec)
{
	try
	{
		if (toSign < 1 || toSign > 150)
			throw (Form::GradeTooHighException());
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << "'s toSign " << e.what() << std::endl;
	}
	try
	{
		if (toExec < 1 || toExec > 150)
			throw (Form::GradeTooLowException());
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << "'s toExec " << e.what() << std::endl;
	}
	return ;
}

Form::Form(const Form &src) : _toSign(src._toSign), _toExec(src._toExec)
{
	*this = src;
	return ;
}

Form::~Form(void)
{
	return ;
}

Form			&Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_signed = src._signed;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Form &src)
{
	out << "{[" << src.getName() << "][" << src.getSigned() << "][" << src.getToSign() << "][" << src.getToExec() << "]}";
	return (out);
}

std::string		Form::getName(void) const
{
	return (this->_name);
}

bool			Form::getSigned(void) const
{
	return (this->_signed);
}

unsigned int	Form::getToSign(void) const
{
	return (this->_toSign);
}

unsigned int	Form::getToExec(void) const
{
	return (this->_toExec);
}

const char		*Form::GradeTooHighException::what(void) const throw()
{
	return ((char *)"Grade is too high");
}

const char		*Form::GradeTooLowException::what(void) const throw()
{
	return ((char *)"Grade is too low");
}

void			Form::beSigned(const Bureaucrat bur)
{
	if (bur.getGrade() > this->getToSign())
		throw (Form::GradeTooLowException());
	this->_signed = true;
	return ;
}
