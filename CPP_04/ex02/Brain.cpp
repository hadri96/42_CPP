/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:54:50 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 15:58:09 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain default constructor" << std::endl; };

Brain::Brain(Brain &other): n(other.n)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < other.n; i++)
		ideas[i] = other.ideas[i];
}
Brain &Brain::operator=(Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < other.n; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

std::string* Brain::getIdeas() const
{
	return (std::string *) ideas;
}

void Brain::addIdea(std::string idea)
{
	if (n + 1 < 100)
		ideas[n++] = idea;
	else
		std::cout << "The brain is already full!" << std::endl;
}
