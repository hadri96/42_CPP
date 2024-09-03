/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:08:30 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 12:08:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	damage = 30;
	health = 100;
	energy = 100;
}

FragTrap::FragTrap(std::string n): ClapTrap(n)
{
	std::cout << "FragTrap constructor called" << std::endl;
	name = n;
	damage = 30;
	health = 100;
	energy = 100;
}

FragTrap::FragTrap(FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << name << " requests a HighFive!✋" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (!energy)
	{
		std::cout << "FragTrap " << name << " can't attack because it has run out of energy" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " attacks " << target
			  << " causing " << damage << " points of damage !"
			  << std::endl;
	energy--;
}
