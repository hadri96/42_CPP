/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:07:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 12:07:52 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
	name = "Tom";
}

ScavTrap::ScavTrap(std::string n): ClapTrap(n)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in GateKeeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!energy)
	{
		std::cout << "ScavTrap " << name << " can't attack because it has run out of energy" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target
			  << " causing " << damage << " points of damage !"
			  << std::endl;
	energy--;
}
