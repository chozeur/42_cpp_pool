/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:35:40 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 15:11:14 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "./Animal.hpp"
# include "./Brain.hpp"

class	Cat : public Animal {

public:
	Cat(void);
	Cat(const Cat &src);
	~Cat(void);

	Cat		&operator=(const Cat &src);

	void	makeSound(void) const;
	void	extractIdeas(void);

private:
	Brain	*_brain;
};

#endif
