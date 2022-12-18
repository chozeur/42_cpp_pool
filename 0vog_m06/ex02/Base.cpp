/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:45 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/18 17:03:25 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# include "./Base.hpp"
#endif

Base	*generate(void)
{
	srand(time(0));
	int	r = rand();

	if (r % 3 == 1)
		return (new A);
	else if (r % 3 == 2)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "real type is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "real type is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "real type is C" << std::endl;
	else
		std::cout << "no A nor B nor C" << std::endl;
	return ;
}

void	identify(Base &p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "real type is A" << std::endl;
	} catch (std::exception &bca) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "real type is B" << std::endl;
		} catch (std::exception &bcb) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "real type is C" << std::endl;
			} catch (std::exception &bcc) {
				std::cout << "no A nor B nor C" << std::endl;
			}
		}
	}
	return ;
}
