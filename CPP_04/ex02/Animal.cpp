/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:24:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/05 15:43:27 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
	type = "Mammal";
}

AAnimal::AAnimal(std::string t): type(t)
{
	std::cout << "AAnimal parameterized constructor called" << std::endl;
}
AAnimal::AAnimal(AAnimal &other): type(other.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}
AAnimal &AAnimal::operator=(AAnimal &other)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.getType();
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}
void AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal " << type << " blobs" << std::endl;
}

std::string AAnimal::getType(void) const { return (type) ;}

void AAnimal::setType(std::string t) { type = t; }

