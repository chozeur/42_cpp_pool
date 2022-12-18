/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:50:24 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/22 23:30:29 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class	Harl{

public:

	void	complain(std::string level);
	Harl(void);
	~Harl(void);

private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	typedef void (Harl::*ftab)(void);
	ftab	_ftab[25];
};

#endif
