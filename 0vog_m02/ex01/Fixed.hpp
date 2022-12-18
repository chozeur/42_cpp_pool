/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:54:38 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/07 17:24:50 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {

public:

	//	CONSTRUCTEURS & DESTRUCTEUR
	Fixed(void);
	Fixed(const Fixed &src);	//	constructeur de recopie
	Fixed(const int val);		//	constructeur depuis entier -> virgule fixe
	Fixed(const float val);		//	constructeur depuis flottant -> virgule fixe
	~Fixed(void);

	//	SURCHARGE D'OPPERATEUR
	Fixed	&operator=(const Fixed &src);

	//	ACCESSEURS
	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	//	FONCTIONS MEMBRES
	float	toFloat(void) const;	//	convertit fixed en flottant
	int		toInt(void) const;		//	convertit fixed en int

private:
	int					_val;
	static const int	_nbit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &itm);

#endif

