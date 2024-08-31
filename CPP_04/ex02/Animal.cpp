/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:24:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 16:24:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Mammal";
}

AAnimal::AAnimal(std::string t): type(t), brain(new Brain)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}
AAnimal::AAnimal(AAnimal &other): type(other.type), brain(new Brain(*other.brain))
{
	std::cout << "Animal copy constructor called" << std::endl;
}
AAnimal &AAnimal::operator=(AAnimal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.getType();
		brain = new Brain(*other.brain);
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	delete brain;
	std::cout << "Animal destructor called" << std::endl;
}
void AAnimal::makeSound( void ) const
{
	std::cout << "Animal " << type << " blobs" << std::endl;
}

std::string AAnimal::getType(void) const { return (type) ;}

void AAnimal::setType(std::string t) { type = t; }
