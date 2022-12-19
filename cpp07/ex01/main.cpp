/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:15:23 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 15:43:53 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# include "./iter.hpp"
#endif

int	main(void)
{
	int	tab1[42] = {0};
	std::string	tab2[3] = {"Hello", " ", "World!"};

	::iter(tab1, 42, ::printSlotAddress);
	::iter(tab1, 42, ::printSlotValue);

	::iter(tab2, 3, ::printSlotAddress);
	::iter(tab2, 3, ::printSlotValue);

	return (0);
}

// #include <iostream>
// #include <string>
// #include "iter.hpp"

// // main sujet
// class Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }
// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
// 	int tab[] = { 0, 1, 2, 3, 4 };	// <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];

// 	iter( tab, 5, print<int> );
// 	iter( tab2, 5, print<Awesome> );

// 	return 0;
// }
