/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:13:15 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/22 00:28:12 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class	Array {

public:
	Array(void): _tab(NULL), _size(0) {}
	Array(unsigned int n): _tab(new T[n]()), _size(n) {}
	Array(const Array &src): _tab(NULL) {*this = src;}
	~Array(void) {
		if (this->_tab)
			delete[] this->_tab;
	}

	Array	&operator=(const Array &src) {
		if (this == &src)
			return (*this);
		if (this->_tab) {
			delete[] this->_tab;
			this->_tab = NULL;
		}
		this->_size = src._size;
		this->_tab = new T[this->_size]();
		for (size_t i = 0; i < this->_size; i++)
			this->_tab[i] = src._tab[i];
		return (*this);
	}

	T	&operator[](int i) {
		if (static_cast<size_t>(i) >= this->_size || static_cast<size_t>(i) < 0)
			throw (std::exception());
		else
			return (this->_tab[i]);
	}

	size_t	size(void) const {
		return (this->_size);
	}

private:
	T		*_tab;
	size_t	_size;
};

#endif
