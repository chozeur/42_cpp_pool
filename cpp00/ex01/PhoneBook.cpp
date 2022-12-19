/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:54:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 15:49:48 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

PhoneBook::PhoneBook(void) : _cnum(0), _i(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

Contact	*PhoneBook::get_contacts(void) const
{
	return ((Contact *)this->_contacts);
}

int	PhoneBook::get_cnum(void) const
{
	return (this->_cnum);
}

void	PhoneBook::set_cnum(int cnum)
{
	this->_cnum = cnum;
	return ;
}

int	PhoneBook::get_i(void) const
{
	return (this->_i);
}

void	PhoneBook::set_i(int i)
{
	this->_i = i;
	return ;
}

bool	PhoneBook::add_contact(void)
{
	this->get_contacts()[this->get_i()].init_contact();
	if (this->get_i() < 7)
	{
		this->set_i(this->get_i() + 1);
		if (this->get_cnum() < 8)
			this->set_cnum(this->get_cnum() + 1);
	}
	else if (this->get_i() == 7)
	{
		this->set_i(0);
		this->set_cnum(8);
	}
	return (true);
}

void	PhoneBook::print_book(void) const
{

	std::cout << "\033[1;4m\033[1;31m                                             \033[0m\033[1;24m" << std::endl;
	std::cout << "\033[1;4m\033[1;31m\033[1;44m|  index   |first name|last  name| nickname |\033[0m\033[1;24m" << std::endl;
	for (int i = 0; i < this->get_cnum(); i++)
	{
		std::stringstream	ss;
		ss << i + 1;
		std::cout << "\033[1;4m\033[1;32m\033[1;44m|" << format_string(ss.str()) \
			<< "|" << format_string(this->get_contacts()[i].get_first_name()) \
			<< "|" << format_string(this->get_contacts()[i].get_last_name()) \
			<< "|"	<< format_string(this->get_contacts()[i].get_nickname()) \
			<< "|\033[1;24m\033[0m\033[1m" << std::endl;
	}
	return ;
}

void	PhoneBook::search(void) const
{
	int buf;

	std::cout << std::endl;
	this->print_book();
	std::cout << std::endl;
loop:
	std::cout << "Enter the desired contact index (0 to exit): ";
	std::cout << "\033[0m";
	std::cin >> buf;
	if (std::cin.eof())
		exit(EXIT_FAILURE);
	std::cout << "\033[1m";
	if (buf <= 0 || buf > this->get_cnum())
	{
		if (!buf)
			goto end;
		std::cout << std::endl \
			<< "\033[1;31mWrong index\033[0m\033[1m" \
			<< std::endl << std::endl;
		goto loop;
	}
	std::cout << std::endl;
	this->get_contacts()[buf - 1].print_contact();
end :
	std::cout << std::endl;
	return ;
}
