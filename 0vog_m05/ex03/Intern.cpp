/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:43:34 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &src)
{
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	ShrubberyCreationForm	shrub(target);
	RobotomyRequestForm		robot(target);
	PresidentialPardonForm	pres(target);

	std::map<std::string, AForm*>	forms;
	forms.insert(std::make_pair("shrubbery creation", &shrub));
	forms.insert(std::make_pair("robotomy request", &robot));
	forms.insert(std::make_pair("presidential pardon", &pres));
	return (forms[name]);
}
