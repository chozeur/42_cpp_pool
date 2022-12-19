/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:57:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/11 17:21:28 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "./Animal.hpp"

class	Dog : public Animal {

public:
	Dog(void);
	Dog(const Dog &src);
	~Dog(void);

	Dog		&operator=(const Dog &src);

	void	makeSound(void) const;
};

#endif
