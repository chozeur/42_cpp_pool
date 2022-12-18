/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:54:38 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/07 17:24:56 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {

public:
	Fixed(void);
	Fixed(const Fixed &src);
	~Fixed(void);

	Fixed	&operator=(const Fixed &src);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

private:
	int					_val;
	static const int	_nbit = 8;
};

#endif
