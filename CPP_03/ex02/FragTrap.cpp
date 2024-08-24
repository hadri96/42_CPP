/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:18:28 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/23 14:22:22 by hmorand          ###   ########.ch       */
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

FragTrap &FragTrap::operator=(FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << name << " requests a HighFive!✋" << std::endl;
}
