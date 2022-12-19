/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:16:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/11 02:22:17 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "./ClapTrap.hpp"

class	FragTrap : public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	~FragTrap(void);

	FragTrap	&operator=(const FragTrap &src);

	void		highFiveGuys(void) const;
};

#endif
