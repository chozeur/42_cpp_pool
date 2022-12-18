/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:29:37 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Formulaire de creation d'arbustes

#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm::AForm("ShrubberyCreationForm", 145, 137), _target("NO_TARGET")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	AForm::AForm(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch (std::exception &e)
	{
		throw;
	}

	std::ofstream	file;
	std::string		fileName = this->_target + "_shrubbery";
	file.open(fileName.c_str(), std::ios::app);
	file << TREE;
	return ;
}
