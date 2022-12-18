/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:14:58 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 15:43:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T tab[], size_t size, void(*function)(const T &item))
{
	for (size_t i = 0; i < size; i++)
		function(tab[i]);
	return ;
}

/*------------------------------------------------------------------*/

template<typename T>
void	printSlotAddress(const T &item)
{
	std::cout << &item << std::endl;
	return ;
}

template<typename T>
void	printSlotValue(const T &item)
{
	std::cout << item << std::endl;
	return ;
}

#endif
