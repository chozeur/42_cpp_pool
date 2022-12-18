/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:38:29 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/22 18:25:12 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

bool	File::read_file(void)
{
	if (!this->_ifs.is_open())
		return (false);
	while (this->_ifs.good())
	{
		std::string	tmp;
		std::getline(this->_ifs, tmp);
		if (tmp.empty() && !this->_ifs.good())
			break ;
		this->_fileStr.append(tmp);
		this->_fileStr.append("\n");
	}
	return (true);
}

bool	File::write_file(std::string str)
{
	if (!this->_ofs.is_open())
		return (false);
	this->_ofs << str;
	this->_ofs.close();
	return (true);
}

std::string	File::get_fileStr(void) const
{
	return (this->_fileStr);
}

File::File(std::string path, int mode)
{
	this->_ifs.open(path.c_str());
	if (mode == READ)
		this->read_file();
	else if (mode == WRITE)
		this->_ofs.open(path.c_str());
}

File::~File()
{
	if (this->_ifs.is_open())
		this->_ifs.close();
	else if (this->_ofs.is_open())
		this->_ofs.close();
}
