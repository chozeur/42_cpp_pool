/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 02:35:40 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/11 17:18:06 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "./Animal.hpp"

class	Cat : public Animal {

public:
	Cat(void);
	Cat(const Cat &src);
	~Cat(void);

	Cat		&operator=(const Cat &src);

	void	makeSound(void) const;
};

#endif
