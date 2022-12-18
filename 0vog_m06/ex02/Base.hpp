/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:52:02 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/18 17:01:26 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

class	Base {

public:
	virtual ~Base(void){}
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
