/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:29:47 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 17:32:12 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const &other): AMateria(other) {}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals" << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure() {}
