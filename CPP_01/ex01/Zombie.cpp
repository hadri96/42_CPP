/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:07:49 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:07:49 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string n): name(n) {}

Zombie::~Zombie()
{
	std::cout << "🧟‍♂️ " << name << " has perished 💀" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	if (!zombie)
		return (NULL);
	return (zombie);
}




