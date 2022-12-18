/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:35:46 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/22 01:11:13 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

class	Weapon{

public:
	const std::string	&getType(void) const;
	bool				setType(std::string type);
	Weapon(std::string type);
	~Weapon(void);

private:

	std::string	_type;
};

#endif
