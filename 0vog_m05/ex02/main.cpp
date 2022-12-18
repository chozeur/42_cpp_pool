/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:26 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	alice("Alice", 42);
	Bureaucrat	bob("Bob", 128);
	Bureaucrat	root("root", 1);

	ShrubberyCreationForm	shrub("garden");
	RobotomyRequestForm		robot("Eliot");
	PresidentialPardonForm	pres("Jack");

	alice.signForm(shrub);		// alice can sign shrub
	bob.signForm(robot);		// bob can't sign robot
	root.signForm(pres);		// root can sign pres

	bob.executeForm(shrub);		// bob can execute shrub
	root.executeForm(robot);	// root can't execute robot (not signed)
	alice.executeForm(pres);	// alice can't execute pres

	alice.signForm(robot);		// alice can sign robot
	alice.executeForm(robot);	// alice can execute robot
	root.executeForm(pres);		// root can execute pres

	return (0);
}
