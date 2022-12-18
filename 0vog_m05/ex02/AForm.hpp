/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:23:18 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/01 12:33:18 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {

public:
	AForm(void);
	AForm(std::string name, const int toSign, const int toExec);
	AForm(const AForm &src);
	~AForm(void);

	AForm	&operator=(const AForm &src);

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
	class	NotSignedException : public std::exception {

	public :
		const char	*what(void) const throw();
	};

	void			beSigned(const Bureaucrat bur);
	virtual void	execute(const Bureaucrat &executor) const = 0;

private:
	std::string			_name;
	bool				_signed;
	const unsigned int	_toSign;
	const unsigned int	_toExec;
};

std::ostream	&operator<<(std::ostream &out, const AForm &src);

#endif
