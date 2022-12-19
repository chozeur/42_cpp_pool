/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:51:09 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/12 22:21:32 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define DFT "DEFAULT CONSTRUCTOR CALLED"
# define CPY "COPY CONSTRUCTOR CALLED"

class	Animal {

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &src);
	virtual ~Animal(void);

	Animal	&operator=(const Animal &src);

	std::string	getType(void) const;
	void		setType(std::string type);

	virtual void	makeSound(void) const;

protected:
	std::string	_type;
};

#endif
