/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:34:06 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/22 17:06:20 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <fstream>
# include <iostream>

# define WRITE 1
# define READ 2

class	File{

public:

	bool		read_file(void);
	bool		write_file(std::string);
	std::string	get_fileStr(void) const;
	File(std::string path, int mode);
	~File();

private:

	std::ifstream	_ifs;
	std::ofstream	_ofs;
	std::string		_fileStr;
};

#endif
