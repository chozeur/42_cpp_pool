/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:47:22 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/08 16:58:40 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "./Contact.hpp"

class	PhoneBook{

public:

	PhoneBook(void);
	~PhoneBook(void);
	Contact	*get_contacts(void) const;
	int		get_cnum(void) const;
	void	set_cnum(int cnum);
	int		get_i(void) const;
	void	set_i(int i);
	bool	add_contact(void);
	void	search(void) const;
	void	print_book(void) const;

private:
	Contact	_contacts[8];
	int		_cnum;
	int		_i;
};

#endif
