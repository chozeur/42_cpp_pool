/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:02:39 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/21 17:25:03 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# include "./whatever.hpp"
#endif

// int	main(void)
// {
// 	int	a = 42;
// 	int	b = 21;
// 	int	c = a;

// 	char	x = '*';
// 	char	y = 'A';
// 	char	z = x;

// 	std::cout << "int" << std::endl;
// 	std::cout << "TEST SWAP :" << std::endl
// 		<< "\ta = " << a << " and b = " << b << std::endl;
// 	swap<int>(a, b);
// 	std::cout << "\ta = " << a << " and b = " << b << std::endl;
// 	std::cout << std::endl << "TEST min & max :" << std::endl
// 		<< "\tmin<int>(a, b) = " << min<int>(a, b) << std::endl
// 		<< "\tmax<int>(b, c) = " << max<int>(b, c) << std::endl;

// 	std::cout << std::endl << std::endl;

// 	std::cout << "char" << std::endl;
// 	std::cout << "TEST SWAP :" << std::endl
// 		<< "\tx = " << x << " and y = " << y << std::endl;
// 	swap<char>(x, y);
// 	std::cout << "\tx = " << x << " and y = " << y << std::endl;
// 	std::cout << std::endl << "TEST min & max :" << std::endl
// 		<< "\tmin<char>(x, y) = " << min<char>(x, y) << std::endl
// 		<< "\tmax<char>(y, z) = " << max<char>(y, z) << std::endl;

// 	return (0);
// }

int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}
