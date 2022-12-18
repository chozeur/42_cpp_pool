/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:29:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Formulaire de pardon presidentiel

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm::AForm("PresidentialPardonForm", 25, 5), _target("NO_TARGET")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	AForm::AForm(src)
{
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch (std::exception &e)
	{
		throw;
	}

	std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}
