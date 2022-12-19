/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:38:26 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 19:00:01 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include <cstdlib>

class	Span {

public:
	Span(const unsigned int N);
	Span(const Span &src);
	~Span(void);

	Span	&operator=(const Span &src);

	void			addNumber(int nb);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;
	template<typename T>
	void			fillRange(typename T::iterator begin, typename T::iterator end);

private:
	unsigned int	_N;
	std::list<int>	_lst;
	Span(void);
};

template<typename T>
void	Span::fillRange(typename T::iterator begin, typename T::iterator end)
{
	for (typename T::iterator it = begin; it != end; it++)
		this->addNumber(*it);
	return ;
}

#endif
