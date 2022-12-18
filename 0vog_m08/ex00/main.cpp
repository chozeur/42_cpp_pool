/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:59:17 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 17:05:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# include "./easyfind.hpp"
#endif
# include <list>
# include <vector>

int	main(void)
{
	std::list<int>	list;

	for (int i = 0; i < 84; i++)
		list.push_back(i);

	std::cout << "Is 42 in the list ?   -> " << easyfind(list, 42) << std::endl;
	std::cout << "Is -21 in the list ?  -> " << easyfind(list, -21) << std::endl;
	std::cout << "Is 1024 in the list ? -> " << easyfind(list, 1024) << std::endl;

	std::cout << std::endl << std::endl;

	std::vector<int>	vect;

	for (int i = 0; i < 42; ++i)
		vect.push_back(i * 42);
	std::cout << "Is 42 in the vect ?   -> " << easyfind(vect, 42) << std::endl;
	std::cout << "Is 126 in the vect ?  -> " << easyfind(vect, 126) << std::endl;
	std::cout << "Is 420 in the vect ? -> " << easyfind(vect, 420) << std::endl;

	return (0);
}
