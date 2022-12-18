/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:11:00 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/22 01:29:06 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanA{

public:
	void	attack(void) const;
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

private:
	std::string	_name;
	Weapon		&_weapon;
};
