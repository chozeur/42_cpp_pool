/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:29:12 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/01 21:53:22 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Formulaire de pardon presidentiel

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "./AForm.hpp"

class	PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);

	void	execute(const Bureaucrat &executor) const;

private:
	std::string	_target;
};

#endif
