/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:23:47 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/05 15:44:38 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		brain = new Brain(*other.brain);
	}
	return (*this);
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "AAnimal " << type << " barks" << std::endl;
}
