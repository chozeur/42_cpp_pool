/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_str.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:53:57 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/15 14:03:27 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ex04.hpp"

std::string	sed_str(std::string str, std::string s1, std::string s2)
{
	int			pos = 0;

	if (s1 == "")
		return (str);
	pos = str.find(s1, pos);
	while (pos != (int)std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos = str.find(s1, pos);
	}
	return (str);
}
