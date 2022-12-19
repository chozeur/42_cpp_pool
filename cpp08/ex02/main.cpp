/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:06 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/13 19:11:17 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_HPP
# include "./MutanStack.hpp"
#endif

int	main(void)
{
	{
		MutanStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutanStack<int>::iterator	it = mstack.begin();
		MutanStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}

		std::stack<int>	s(mstack);

		std::cout << "s size = " << s.size() << std::endl;
		std::cout << "mstack size = " << mstack.size() << std::endl;
	}
	std::cout << "------------------------" << std::endl
		<< "------------------------" << std::endl;
	{
		std::list<int>	rstack;

		rstack.push_back(5);
		rstack.push_back(17);

		std::cout << *(++rstack.begin()) << std::endl;

		rstack.pop_back();

		std::cout << rstack.size() << std::endl;

		rstack.push_back(3);
		rstack.push_back(5);
		rstack.push_back(737);
		//[...]
		rstack.push_back(0);

		std::list<int>::iterator	it = rstack.begin();
		std::list<int>::iterator	ite = rstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	return (0);
}
