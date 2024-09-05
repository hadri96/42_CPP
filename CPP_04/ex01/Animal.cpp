/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:59:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/05 15:43:09 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Mammal";
}

Animal::Animal(std::string t): type(t)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}
Animal::Animal(Animal &other): type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal &Animal::operator=(Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
void Animal::makeSound( void ) const
{
	std::cout << "Animal " << type << " blobs" << std::endl;
}

std::string Animal::getType(void) const { return (type) ;}

void Animal::setType(std::string t) { type = t; }