/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:05:55 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/12 12:38:29 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# include "./Base.hpp"
#endif

int	main(void)
{
	Base	*x = new A;
	Base	*y = generate();
	Base	z;
	C		c;

	std::cout << "x's "; identify(x);
	std::cout << "y's "; identify(*y);
	std::cout << "z's "; identify(*(&z));
	std::cout << "c's "; identify(c);

	delete x;
	delete y;

	return (0);
}
