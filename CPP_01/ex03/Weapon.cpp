/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:53:35 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:53:35 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string t): type(t) {}

Weapon::~Weapon() {}

std::string const Weapon::getType( void ) const
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
