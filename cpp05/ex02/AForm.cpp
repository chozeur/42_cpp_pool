/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:48:30 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:56 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm(void) : _name("NO_NAME"), _signed(false), _toSign(1), _toExec(1)
{
	return ;
}

AForm::AForm(std::string name, const int toSign, const int toExec) : _name(name), _signed(false), _toSign(toSign), _toExec(toExec)
{
	try
	{
		if (toSign < 1 || toSign > 150)
			throw (AForm::GradeTooHighException());
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << "'s toSign " << e.what() << std::endl;
	}
	try
	{
		if (toExec < 1 || toExec > 150)
			throw (AForm::GradeTooLowException());
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << "'s toExec " << e.what() << std::endl;
	}
	return ;
}

AForm::AForm(const AForm &src) : _toSign(src._toSign), _toExec(src._toExec)
{
	*this = src;
	return ;
}

AForm::~AForm(void)
{
	return ;
}

AForm			&AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_signed = src._signed;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &src)
{
	out << "{[" << src.getName() << "][" << src.getSigned() << "][" << src.getToSign() << "][" << src.getToExec() << "]}";
	return (out);
}

std::string		AForm::getName(void) const
{
	return (this->_name);
}

bool			AForm::getSigned(void) const
{
	return (this->_signed);
}

unsigned int	AForm::getToSign(void) const
{
	return (this->_toSign);
}

unsigned int	AForm::getToExec(void) const
{
	return (this->_toExec);
}

const char		*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char		*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char		*AForm::NotSignedException::what(void) const throw()
{
	return ("Signature missing");
}

void			AForm::beSigned(const Bureaucrat bur)
{
	if (bur.getGrade() > this->getToSign())
		throw (AForm::GradeTooLowException());
	this->_signed = true;
	return ;
}

void			AForm::execute(const Bureaucrat &executor) const
{
	if (this->_toExec < executor.getGrade())
		throw (AForm::GradeTooHighException());
	if (!this->_signed)
		throw (AForm::NotSignedException());
	return ;
}
