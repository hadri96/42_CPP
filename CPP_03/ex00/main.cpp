/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:07:53 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 21:07:53 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("John");
	clap1.setHealth(100);
	clap1.setEnergy(50);
	clap1.setDamage(20);
	assert(clap1.getHealth() == 100);
	assert(clap1.getEnergy() == 50);
	assert(clap1.getDamage() == 20);
	std::cout << "Test 1 passed: Default Constructor and Setters/Getters" << std::endl;

	ClapTrap clap2(clap1);
	assert(clap2.getHealth() == 100);
	assert(clap2.getEnergy() == 50);
	assert(clap2.getDamage() == 20);
	std::cout << "Test 2 passed: Copy Constructor" << std::endl;

	ClapTrap clap3("Tim");
	clap3 = clap1;
	assert(clap3.getHealth() == 100);
	assert(clap3.getEnergy() == 50);
	assert(clap3.getDamage() == 20);
	std::cout << "Test 3 passed: Assignment Operator" << std::endl;

	clap1.attack("Target");
	assert(clap1.getEnergy() == 49);
	std::cout << "Test 4 passed: Attack Method" << std::endl;

	clap1.takeDamage(30);
	assert(clap1.getHealth() == 70);
	std::cout << "Test 5 passed: Take Damage Method" << std::endl;

	clap1.beRepaired(20);
	assert(clap1.getHealth() == 90);
	assert(clap1.getEnergy() == 48);
	std::cout << "Test 6 passed: Be Repaired Method" << std::endl;
	return 0;
}
