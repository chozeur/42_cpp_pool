/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:53:44 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/17 18:05:28 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIAL_HPP
# include "./serial.hpp"
#endif

int	main(void)
{
	Data	a;

	a.nb = 42;
	a.c = '*';

	std::cout << "BEFORE :" << std::endl << "a.nb = " << a.nb << "\ta.c = " << a.c
		<< std::endl << std::endl
		<< "Data *b = deserialize(serialize(&a))"
		<< std::endl << std::endl;
		
	Data	*b = deserialize(serialize(&a));

	std::cout << "AFTER :" << std::endl << "b->nb = " << b->nb << "\tb->c = " << b->c << std::endl;

	return (0);
}
