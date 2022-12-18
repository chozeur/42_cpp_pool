/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:30:28 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/22 01:04:49 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB{

public:
	void	attack(void) const;
	bool	setWeapon(Weapon *weapon);
	HumanB(std::string name);
	~HumanB(void);

private:
	Weapon		*_weapon;
	std::string	_name;
};
