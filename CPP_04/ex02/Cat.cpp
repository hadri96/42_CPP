/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:43:46 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/05 15:43:57 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain;
}

Cat::Cat(Cat &other): AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		brain = new Brain(*other.brain);
	}
	return (*this);
}
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;

}

void Cat::makeSound(void) const
{
	std::cout << "AAnimal " << type << " meows" << std::endl;
}
