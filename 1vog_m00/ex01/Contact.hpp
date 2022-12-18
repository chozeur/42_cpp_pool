/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:25:00 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/21 19:17:15 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class	Contact{

public:

	Contact(void);
	~Contact(void);
	bool		get_set(void) const;
	bool		set_set(void);
	std::string	get_first_name(void) const;
	bool		set_first_name(void);
	std::string	get_last_name(void) const;
	bool		set_last_name(void);
	std::string	get_nickname(void) const;
	void		set_nickname(void);
	std::string	get_phone_number(void) const;
	bool		set_phone_number(void);
	std::string	get_secret(void) const;
	void		set_secret(void);
	void		init_contact(void);
	void		print_contact(void) const;
	void		clear_contact(void);

private:

	bool		_is_set;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
};

#endif
