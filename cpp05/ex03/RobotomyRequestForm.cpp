/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:29:34 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Formulaire de demande de robotomie

#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm::AForm("RobotomyRequestForm", 72, 45), _target("NO_TARGET")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm::AForm(src)
{
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch (std::exception &e)
	{
		throw;
	}

	std::cout << "BRR BRRRR BR (bruits de perceuse)" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomised succesfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomisation has failed" << std::endl;
}
