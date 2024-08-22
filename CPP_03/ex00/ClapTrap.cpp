/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:08:24 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 21:10:37 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	energy = 10;
	damage = 0;
	health = 10;
}

ClapTrap::ClapTrap(std::string n): name(n) {}

ClapTrap::ClapTrap(ClapTrap &other)
{
	*this = other;
}

ClapTrap::~ClapTrap() {}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		energy = other.getEnergy();
		damage = other.getDamage();
		health = other.getHealth();
		name = other.getName();
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
	std::cout << "ClapTrap " << name << " attacks" << target
			  << " causing "<< damage << " points of damage !"
			  << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage!" << std::endl;
	health -= amount; }

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " is repaired and gains " << amount
			  << " points of health back!" << std::endl;
	health += amount;
	energy--;
}
