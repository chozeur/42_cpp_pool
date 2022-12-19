/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:32:50 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/29 19:44:41 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

# define DFT "DEFAULT CONSTRUCTOR CALLED"
# define CPY "COPY CONSTRUCTOR CALLED"

class	WrongAnimal {

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal(void);

	WrongAnimal	&operator=(const WrongAnimal &src);

	std::string	getType(void) const;
	void		setType(std::string type);

	void	makeSound(void) const;

protected:
	std::string	_type;
};

#endif
