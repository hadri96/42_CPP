/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:23:47 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 16:23:47 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
		AAnimal::operator=(other);
	return (*this);
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Animal " << type << " barks" << std::endl;
}
