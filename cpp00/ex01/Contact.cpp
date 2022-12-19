/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:24:32 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/11 15:25:20 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex01.hpp"

Contact::Contact(void) : _is_set(0)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

bool	Contact::get_set(void) const
{
	return (this->_is_set);
}

bool	Contact::set_set(void)
{
	if (this->_is_set)
		return (false);
	this->_is_set = true;
	return (true);
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

bool	Contact::set_first_name(void)
{
	set_field(&this->_first_name);
	if (!char_only(this->_first_name))
	{
		std::cout << std::endl << "First name must contain alphabetic chars only" \
			<< std::endl << std::endl;
		return (false);
	}
	return (true);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

bool	Contact::set_last_name(void)
{
	set_field(&this->_last_name);
	if (!char_only(this->_last_name))
	{
		std::cout << std::endl \
			<< "Last name must contain alphabetic chars only" \
			<< std::endl << std::endl;
		return (false);
	}
	return (true);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

void	Contact::set_nickname(void)
{
	set_field(&this->_nickname);
	return ;
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

bool	Contact::set_phone_number(void)
{
	set_field(&this->_phone_number);
	if (!num_only(this->_phone_number))
	{
		std::cout << std::endl \
			<< "Phone number must contain numeric chars only" \
			<< std::endl << std::endl;
		return (false);
	}
	return (true);
}

std::string	Contact::get_secret(void) const
{
	return (this->_darkest_secret);
}

void	Contact::set_secret(void)
{
	std::cout << "\033[0m";
	this->_darkest_secret.clear();
	while (this->_darkest_secret.empty())
	{
		std::getline(std::cin, this->_darkest_secret);
		std::cin.clear();
	}
	std::cout << "\033[1m";
	return ;
}

void	Contact::init_contact(void)
{
	std::cout << std::endl;
fn:
	std::cout << "👤 First Name : ";
	if (!this->set_first_name())
		goto fn;
ln:
	std::cout << "👤 Last Name : ";
	if (!this->set_last_name())
		goto ln;
	std::cout << "👤 Nickname : ";
	this->set_nickname();
pn:
	std::cout << "📞 Phone Number : ";
	if (!this->set_phone_number())
		goto pn;
	std::cout << "😈 Darkest Secret : ";
	this->set_secret();
	std::cout << std::endl;
	this->_is_set = 1;
	return ;
}

void	Contact::print_contact(void) const
{
	std::cout << "👤 : " << this->_first_name << std::endl;
	std::cout << "👤 : " << this->_last_name << std::endl;
	std::cout << "👤 : " << this->_nickname << std::endl;
	std::cout << "📞 : " << this->_phone_number << std::endl;
	std::cout << "😈 : " << this->get_secret() << std::endl;
	return ;
}

void	Contact::clear_contact(void)
{
	this->_darkest_secret.clear();
	this->_first_name.clear();
	this->_last_name.clear();
	this->_nickname.clear();
	this->_phone_number.clear();
	this->_is_set = false;
	return ;
}
