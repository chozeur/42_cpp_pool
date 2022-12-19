/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:12:40 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/11 17:52:18 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX04_H
# define EX04_H

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include "file.hpp"

std::string	get_file(std::string path);
std::string	sed_str(std::string str, std::string s1, std::string s2);

#endif
