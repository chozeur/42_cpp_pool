/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:51:09 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/13 12:17:46 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

# define DFT "DEFAULT CONSTRUCTOR CALLED"
# define CPY "COPY CONSTRUCTOR CALLED"

class	AAnimal {

public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal &src);
	virtual ~AAnimal(void);

	AAnimal	&operator=(const AAnimal &src);

	virtual void	makeSound(void) const = 0;

protected:
	std::string	_type;
};

#endif
