/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:32:58 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/21 19:16:12 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie{

public:
	Zombie(void);
	~Zombie(void);
	std::string	get_name(void) const;
	bool		set_name(std::string);
	void		announce(void) const;

private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
