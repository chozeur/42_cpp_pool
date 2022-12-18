/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:57:06 by flcarval          #+#    #+#             */
/*   Updated: 2022/12/07 16:22:02 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain(void)
{
	static const std::string rand_sentences[] =
	{
		"Why is a building called a building when it has already been built?",
		"If I were a book, what title would I have?",
		"How does our voice in our head sound?",
		"Humans invented the sounds produced by dinosaurs.",
		"The hospital where you were born is the only building you left without entering.",
		"Love just happens and doesn't ask you a question, but gives you an answer.",
		"You have to let some people go, to find yourself.",
		"Before the camera was invented, no one had seen themselves with their eyes closed.",
		"What is the purpose of life?",
		"Do aliens exist and if so, do they also study and send their beings to our planet, as we go to theirs?",
		"What is a person? Is the person mind or body?",
		"If God created the world, who created God?",
		"What if we go to a parallel universe every time we go to sleep?",
		"Children with an imaginary friend are creative, while adults with an imaginary friend are schizophrenics.",
		"When you wait for a waiter, you become a waiter.",
		"Why can't we invent a new color?",
		"What would you do if you could only eat green foods?",
		"If we were called differently, would we behave like a different person?",
		"Do animals think we are aliens because we don't look like them?",
		"The letter x is used more in mathematics than in grammar and sentences.",
		"Friends are the chosen family you love as well as the real family.",
		"If you hit yourself and it hurts, are you strong or weak?",
		"Brushing your teeth is the only time you clean your skeleton.",
		"Do different species of animals communicate with each other, or they need a translator?",
		"What if dogs lick us because they know we have bones inside of us?",
		"If you try to rob a bank, you won't have problems with bills for the next ten years, whether you succeed in the robbery or not",
		"If life is unfair to everyone, does that mean it is fair?",
		"Why is 77 + 33 not 100?",
		"First you learn to read then you read to learn.",
		"What would you do if nobody could remember who you are? ",
		"Butter is a food lotion.",
		"There is only one life, it should be used in the best way!",
		"Don't wait for anything and don't chase after anything. Everything comes when it should.",
		"Your life is only in your hands.",
		"What would you do if you had to run, not walk, everywhere?",
		"When you radiate positive energy, beautiful things will happen.",
		"What would you do if the floor was lava?",
	};
	srand(time(NULL));
	for(int i = 0; i < 100; i++)
	{

		this->_ideas[i] = rand_sentences[rand()%36];
	}
	return ;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	return ;
}

Brain::~Brain(void)
{
	return ;
}

Brain	&Brain::operator=(const Brain &src)
{
	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return (*this);
}

std::string	&Brain::extractIdea(int i)
{
	return (this->_ideas[i]);
}
