/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:47:58 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 16:59:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <numeric>

template<typename T>
bool	easyfind(T tp, int n)
{
	return (std::find(tp.begin(), tp.end(), n) != tp.end() ? true : false);
}

#endif
