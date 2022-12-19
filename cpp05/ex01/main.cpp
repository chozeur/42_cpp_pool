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

int	main(void)
{
	Bureaucrat	alice("Alice", 42);
	Bureaucrat	bob("Bob", 21);

	Form		formA("A", 84, 42);
	Form		formB("B", 10, 21);
	Form		formC("C", 0, 151);	//	Must throw an exception, as grades are invalids

	alice.signForm(formA);
	alice.signForm(formB);			//	Must throw an exception
	bob.signForm(formA);
	bob.signForm(formB);			//	Must throw an exception

	return (0);
}
