/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:42:05 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/21 17:02:20 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_TPP
# define WHATEVER_TPP

# include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	&min(const T &a, const T &b)
{
	return ((a < b) ? a : b);
}

template<typename T>
T const	&max(const T &a, const T &b)
{
	return ((a > b) ? a : b);
}

#endif
