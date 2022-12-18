/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:50:55 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/28 17:32:29 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_HPP
# define MUTAN_STACK_HPP

# include <iostream>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <list>
# include <stack>
# include <vector>
# include <numeric>

template<typename T>
class	MutanStack : public std::stack<T> {

public:
	MutanStack(void) {return ;}
	MutanStack(const MutanStack &src) : std::stack<T>(src) {}
	~MutanStack(void) {return ;}

	MutanStack	&operator=(const MutanStack &src) {
		std::stack<T>::operator=(src);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator	begin(void) {return (this->c.begin());}
	iterator	end(void) {return (this->c.end());}
};

#endif
