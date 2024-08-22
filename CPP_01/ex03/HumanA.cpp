/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:55:17 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 11:55:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w): name(n), weapon(w) {}

HumanA::~HumanA() {}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their "
			  << weapon.getType() << std::endl;
}
