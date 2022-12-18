/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:51:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 16:25:24 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstdlib>

class	Brain {

public:
	Brain(void);
	Brain(const Brain &src);
	~Brain(void);

	Brain	&operator=(const Brain &src);

	std::string	&extractIdea(int i);

protected:
	std::string	_ideas[100];
};

#endif
