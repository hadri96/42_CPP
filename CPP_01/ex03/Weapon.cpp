/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:45:23 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 11:46:41 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string t): type(t) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType( void ) const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
