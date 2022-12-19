/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:25:00 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/17 15:26:21 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
# define SCALAR_CONVERSION_HPP

# include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

class	ScalarConversion {

public:
	ScalarConversion(void);
	ScalarConversion(std::string str);
	ScalarConversion(const ScalarConversion &src);
	~ScalarConversion(void);

	ScalarConversion	&operator=(const ScalarConversion &src);

	class	conversionNonDisplayableException : public std::exception {

	public :
		const char	*what(void) const throw() {
			return ("Non displayable");
		}
	};
	class	conversionImpossibleException : public std::exception {

	public :
		const char	*what(void) const throw() {
			return ("Impossible");
		}
	};

	char	getChar(void) const;
	int		getInt(void) const;
	float	getFloat(void) const;
	double	getDouble(void) const;

private:
	double	_val;
};

#endif
