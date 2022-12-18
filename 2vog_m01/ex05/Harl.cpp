/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:50:22 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/11 18:30:59 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	if (level != "debug" && level != "info" && level != "warning" && level != "error")
		return ;
	(this->*_ftab[(int)level[0] - 97])();
	return ;
}

void	Harl::debug(void)
{
	std::cout << std::endl
		<< "\033[4m" << "\033[1m" << "\033[32m" << "\033[47m"
		<< ". . . . . . . .[DEBUG]. . . . . . . ." << "\033[00m"
		<< std::endl << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << std::endl
		<< "\033[4m" << "\033[1m" << "\033[34m" << "\033[47m"
		<< ".*.*.*.*.*.*.*.[INFO].*.*.*.*.*.*.*." << "\033[00m"
		<< std::endl << std::endl
		<< "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << std::endl
		<< "\033[4m" << "\033[1m" << "\033[31m" << "\033[47m"
		<< ".!.!.!.!.!.!.!.[WARNING].!.!.!.!.!.!.!." << "\033[00m"
		<< std::endl << std::endl
		<< "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month."
		<< std::endl << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << std::endl
		<< "\033[4m" << "\033[1m" << "\033[30m" << "\033[103m"
		<< ".X.X.X.X.X.X.X.[ERROR].X.X.X.X.X.X.X." << "\033[00m"
		<< std::endl << std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
	return ;
}


Harl::Harl(void)
{
	_ftab[(int)'d' - 97] = &Harl::debug;
	_ftab[(int)'i' - 97] = &Harl::info;
	_ftab[(int)'w' - 97] = &Harl::warning;
	_ftab[(int)'e' - 97] = &Harl::error;
	return ;
}

Harl::~Harl(void)
{
	return ;
}

