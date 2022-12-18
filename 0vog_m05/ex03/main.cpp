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
#include "./Intern.hpp"

int	main(void)
{
	Intern	a;

	AForm	*form1 = a.makeForm("shrubbery creation", "targ1");
	AForm	*form2 = a.makeForm("robotomy request", "targ2");
	AForm	*form3 = a.makeForm("presidential pardon", "targ3");
	AForm	*form4 = a.makeForm("blabla", "targ4");

	std::cout << "form1 : " << form1 << std::endl;	//	must print the address of form1
	std::cout << "form2 : " << form2 << std::endl;	//	must print the address of form2
	std::cout << "form3 : " << form3 << std::endl;	//	must print the address of form3
	std::cout << "form4 : " << form4 << std::endl;	//	must print NULL as "blabla" is'n an existing form
	return (0);
}
