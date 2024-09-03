/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:45:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 09:49:55 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	name = "Eric";
	energy = 10;
	damage = 0;
	health = 10;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	energy = 10;
	damage = 0;
	health = 10;
	name = n;
}

ClapTrap::ClapTrap(ClapTrap &other): \
name(other.name), damage(other.damage), health(other.health), energy(other.energy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		energy = other.energy;
		damage = other.damage;
		health = other.health;
		name = other.name;
	}
	return (*this);
}

void ClapTrap::setDamage(unsigned int value) { damage = value; }

void ClapTrap::setHealth(unsigned int value) { health = value; }

void ClapTrap::setEnergy(unsigned int value) { energy = value; }

void ClapTrap::setName(std::string n) { name = n; }

unsigned int ClapTrap::getDamage(void) const { return (damage); }

unsigned int ClapTrap::getHealth(void) const { return (health); }

unsigned int ClapTrap::getEnergy(void) const { return (energy); }

std::string  ClapTrap::getName(void) const { return (name); }

void ClapTrap::attack(const std::string &target)
{
	if (!energy)
	{
		std::cout << "ClapTrap " << name << " can't attack because it has run out of energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks" << target
			  << " causing "<< damage << " points of damage !"
			  << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!health)
	{
		std::cout << "ClapTrap " << name
				  << " can't take anymore damage because it's run out of hit points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage!" << std::endl;
	health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy)
	{
		std::cout << "ClapTrap " << name
				  << " can't repair itself because it has run out of energy" << std::endl;
		return ;
	}
	if (!health)
	{
		std::cout << "ClapTrap " << name
				  << " can't repair itself because it has run out of hit points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " is repaired and gains " << amount
			  << " points of health back!" << std::endl;
	health += amount;
	energy--;
}
