/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:27:08 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/25 18:27:08 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	type = "Mammal";
}

WrongAnimal::WrongAnimal(std::string t)
{
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
	type = t;
}
WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal " << type << " blobs" << std::endl;
}

std::string WrongAnimal::getType(void) const { return (type) ;}

void WrongAnimal::setType(std::string t) { type = t; }
