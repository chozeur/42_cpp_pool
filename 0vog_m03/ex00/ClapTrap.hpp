/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:56 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/08 16:57:39 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class	ClapTrap {

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap(void);

	ClapTrap	&operator=(const ClapTrap &src);

	std::string	getName(void) const;
	void		setName(std::string name);
	int			getHp(void) const;
	void		setHp(int hp);
	int			getEp(void) const;
	void		setEp(int ep);
	int			getAd(void) const;
	void		setAd(int ad);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

private:
	std::string	_name;
	int			_hp;	//	Hit points
	int			_ep;	//	Energy points
	int			_ad;	//	Attack damage
};

#endif
