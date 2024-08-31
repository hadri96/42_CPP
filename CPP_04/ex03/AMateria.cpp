/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:27:41 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 17:27:41 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): name(type) {}

AMateria::AMateria(AMateria const &other): name(other.name) {}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		name = other.name;
	return (*this);
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return (name); }
