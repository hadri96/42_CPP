/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:54:23 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:54:23 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string n, Weapon w): name(n), weapon(w) {}

HumanA::~HumanA() {}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their "
			  << this->weapon.getType() << std::endl;
}
