/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:46:17 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 18:31:51 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# include "./Span.hpp"
#endif

Span::Span(void)
{
	return ;
}

Span::Span(const unsigned int N) : _N(N)
{
	return ;
}

Span::Span(const Span &src)
{
	*this = src;
	return ;
}

Span::~Span(void)
{
	return ;
}

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->_N = src._N;
	return (*this);
}

void	Span::addNumber(int nb)
{
	if (this->_lst.size() == this->_N)
		throw (std::exception());
	this->_lst.push_back(nb);
	return ;
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_lst.empty() || this->_lst.size() == 1)
		throw (std::exception());

	std::list<int>	tmp(this->_lst);
	unsigned int	min = this->longestSpan();

	tmp.sort();
	std::list<int>::const_iterator prev;
	for (std::list<int>::const_iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		if (it == tmp.begin())
		{
			prev = it;
			continue ;
		}
		unsigned int	dif = static_cast<unsigned int>(abs(*it - *prev));
		if (dif < min)
			min = dif;
		prev = it;
	}
	return (min);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_lst.empty() || this->_lst.size() == 1)
		throw (std::exception());

	std::list<int>	tmp(this->_lst);

	tmp.sort();
	return (static_cast<unsigned int>(*(tmp.rbegin()) - *(tmp.begin())));
}

// template<typename T>
// void	Span::fillRange(typename T::iterator begin, typename T::iterator end)
// {
// 	for (typename T::iterator it = begin; it != end; it++)
// 		this->addNumber(*it);
// 	return ;
// }
