/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:57:36 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 16:21:01 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

# include "./AAnimal.hpp"
# include "./Brain.hpp"

class	Dog : public AAnimal {

public:
	Dog(void);
	Dog(const Dog &src);
	~Dog(void);

	Dog		&operator=(const Dog &src);

	void	makeSound(void) const;
	void	extractIdeas(void);

private:
	Brain	*_brain;
};

#endif
