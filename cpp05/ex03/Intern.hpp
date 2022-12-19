/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:43:33 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/03 17:30:03 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <map>
# include "./AForm.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./PresidentialPardonForm.hpp"

class	Intern {

public:
	Intern(void);
	Intern(const Intern &src);
	~Intern(void);

	Intern	&operator=(const Intern &src);

	AForm	*makeForm(std::string name, std::string target) const;
};

#endif
