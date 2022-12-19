/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:32:49 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/29 19:36:56 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "./WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

public:
	WrongCat(void);
	WrongCat(const WrongCat &src);
	~WrongCat(void);

	WrongCat		&operator=(const WrongCat &src);

	void	makeSound(void) const;
};

#endif
