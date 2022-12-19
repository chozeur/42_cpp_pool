/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:55:27 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 16:58:45 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ex01.hpp"

int	main(void)
{
	std::string		buf;
	PhoneBook	phonebook;

	std::cout << std::endl << "\033[1m";
	while (1)
	{
		std::cout << "Please enter a command : ";
		set_field(&buf);
		if (!buf.compare("ADD"))
		{
			phonebook.add_contact();
			buf.clear();
		}
		else if (!buf.compare("SEARCH"))
		{
			if (!phonebook.get_cnum())
			{
				std::cout << std::endl << "\033[1;31mPhonebook is empty\033[0m\033[1m" \
					<< std::endl << std::endl;
				buf.clear();
				continue ;
			}
			phonebook.search();
			buf.clear();
		}
		else if (!buf.compare("EXIT"))
			break ;
		else
		{
			std::cout << std::endl << "\033[0mCommands are ADD SEARCH and EXIT\033[1m" \
				<< std::endl << std::endl;
			buf.clear();
			continue ;
		}
	}
	std::cout << "\033[0m";
	return (0);
}

std::string	format_string(std::string str)
{
	std::string		res = str;
	int	l = (int)res.length();

	if (l > 10)
	{
		res.resize(9);
		res.append(".");
	}
	else if (l < 10)
	{
		for (int i = 0; i < 10 - l; i++)
			res.insert(0, " ");
	}
	return (res);
}

void	set_field(std::string *str)
{
	std::cout << "\033[0m";
	str->clear();
	while (str->empty())
	{
		std::getline(std::cin, *str);
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		std::cin.clear();
	}
	std::cout << "\033[1m";
	return ;
}

bool		char_only(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!((str[i] >= 65 && str[i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122)
			|| str[i] == '-'))
			return (false);
	}
	return (true);
}

bool		num_only(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (false);
	}
	return (true);
}

