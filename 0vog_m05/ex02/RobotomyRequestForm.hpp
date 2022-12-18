/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:29:17 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/01 23:47:33 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Formulaire de demande de robotomie

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "./AForm.hpp"
# include <cstdlib>

class	RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);

	void	execute(const Bureaucrat &executor) const;

private:
	std::string	_target;
};

#endif
