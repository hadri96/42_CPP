/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:59:49 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/23 10:05:49 by hmorand          ###   ########.ch       */
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

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	if (this == &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap assignement operator called" << std::endl;
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (!health)
	{
		std::cout << "ScavTrap " << name
				  << " can't take anymore damage because it's run out of hit points" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " takes " << amount
			  << " points of damage!" << std::endl;
	health -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (!energy)
	{
		std::cout << "ScavTrap " << name
				  << " can't repair itself because it has run out of energy" << std::endl;
		return;
	}
	if (!health)
	{
		std::cout << "ScavTrap " << name
				  << " can't repair itself because it has run out of hit points" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " is repaired and gains " << amount
			  << " points of health back!" << std::endl;
	health += amount;
	energy--;
}
