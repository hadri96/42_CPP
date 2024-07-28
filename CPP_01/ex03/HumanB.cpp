/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:58:06 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 11:58:36 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their "
			  << weapon->getType() << std::endl;
}
