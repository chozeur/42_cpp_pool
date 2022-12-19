/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:29:25 by flcarval          #+#    #+#             */
/*   Updated: 2022/10/25 16:13:07 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &src);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	class	GradeTooHighException : public std::exception {

	public:
		const char	*what(void) const throw();
	};
	class	GradeTooLowException : public std::exception {

	public:
		const char	*what(void) const throw();
	};

	void	increaseGrade(void);
	void	decreaseGrade(void);

private:
	const std::string	_name;
	unsigned int		_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif
