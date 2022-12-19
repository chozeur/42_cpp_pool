/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:54:38 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/07 17:24:31 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {

public:

	//	CONSTRUCTEURS & DESTRUCTEUR
	Fixed(void);				//	constructeur par defaut
	Fixed(const Fixed &src);	//	constructeur de recopie
	Fixed(const int val);		//	constructeur depuis entier -> virgule fixe
	Fixed(const float val);		//	constructeur depuis flottant -> virgule fixe
	~Fixed(void);				//	destructeur par defaut

	//	SURCHARGE D'OPPERATEUR
	Fixed	&operator=(const Fixed &right);	//	surcharge de l'operateur =
	bool	operator>(const Fixed &right);	//	surcharge de l'operateur >
	bool	operator<(const Fixed &right);	//	surcharge de l'operateur <
	bool	operator>=(const Fixed &right);	//	surcharge de l'operateur >=
	bool	operator<=(const Fixed &right);	//	surcharge de l'operateur <=
	bool	operator==(const Fixed &right);	//	surcharge de l'operateur ==
	bool	operator!=(const Fixed &right);	//	surcharge de l'operateur !=
	Fixed	operator+(const Fixed &right);	//	surcharge de l'operateur +
	Fixed	operator-(const Fixed &right);	//	surcharge de l'operateur -
	Fixed	operator*(const Fixed &right);	//	surcharge de l'operateur *
	Fixed	operator/(const Fixed &right);	//	surcharge de l'operateur /
	Fixed	&operator++();					//	surcharge de l'operateur ++ (prefix)
	Fixed	operator++(int);				//	surcharge de l'operateur ++ (postfix)
	Fixed	&operator--();					//	surcharge de l'operateur -- (prefix)
	Fixed	operator--(int);				//	surcharge de l'operateur -- (postfix)

	//	ACCESSEURS
	int		getRawBits(void) const;		//	accesseur _val
	void	setRawBits(const int raw);	//	seteur _val

	//	FONCTIONS MEMBRES
	float				toFloat(void) const;					//	convertit fixed en flottant
	int					toInt(void) const;						//	convertit fixed en int
	static Fixed		&min(Fixed &a, Fixed &b);				//	retourne le plus petit de a et b
	static const Fixed	&min(const Fixed &a, const Fixed &b);	//	retourne le plus petit de a et b
	static Fixed		&max(Fixed &a, Fixed &b);				//	retourne le plus grand de a et b
	static const Fixed	&max(const Fixed &a, const Fixed &b);	//	retourne le plus grand de a et b

private:
	int					_val;
	static const int	_nbit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &itm);	//	Surcharge de l'operateur de redirection de flux

#endif

