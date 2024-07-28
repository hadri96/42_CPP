/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:55:04 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:55:04 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string n) : name(n) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their "
			  << this->weapon.getType() << std::endl;
}
