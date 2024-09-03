/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:27:22 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 13:27:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain;
}

Cat::Cat(Cat &other): Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
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
	std::cout << "Animal " << type << " meows" << std::endl;
}
