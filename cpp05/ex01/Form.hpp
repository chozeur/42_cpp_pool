/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:23:18 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/09 15:12:54 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"

class	Bureaucrat;

class	Form {

public:
	Form(void);
	Form(std::string name, const int toSign, const int toExec);
	Form(const Form &src);
	~Form(void);

	Form	&operator=(const Form &src);

	std::string 	getName(void) const;
	bool			getSigned(void) const;
	unsigned int	getToSign(void) const;
	unsigned int	getToExec(void) const;

	class	GradeTooHighException : public std::exception {

	public :
		const char	*what(void) const throw();
	};

	class	GradeTooLowException : public std::exception {

	public :
		const char	*what(void) const throw();
	};

	void	beSigned(const Bureaucrat bur);

private:
	std::string			_name;
	bool				_signed;
	const unsigned int	_toSign;
	const unsigned int	_toExec;
};

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif
