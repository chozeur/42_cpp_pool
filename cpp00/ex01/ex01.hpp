/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:31:48 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 16:57:51 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_HPP
# define EX01_HPP


# include <iostream>
# include <sstream>
# include <cstdlib>
# include "./PhoneBook.hpp"
# include "./Contact.hpp"

std::string	format_string(std::string str);
void		set_field(std::string *str);
bool		char_only(std::string str);
bool		num_only(std::string str);

#endif
