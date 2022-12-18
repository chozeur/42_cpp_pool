/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:50:20 by flcarval          #+#    #+#             */
/*   Updated: 2022/11/15 13:58:44 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	guy;

	guy.complain("debug");
	guy.complain("info");
	guy.complain("warning");
	guy.complain("error");
	return (0);
}
