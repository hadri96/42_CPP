/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:28:15 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 17:28:47 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const &other): AMateria(other) {}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}
