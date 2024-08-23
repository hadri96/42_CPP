/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:05:59 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/23 10:08:19 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav1;
	scav1.attack("Enemy1");
	scav1.takeDamage(20);
	scav1.beRepaired(10);
	scav1.guardGate();
	std::cout << std::string(50, '-') << std::endl;

	ScavTrap scav2("Scavvy");
	scav2.attack("Enemy2");
	scav2.takeDamage(30);
	scav2.beRepaired(20);
	scav2.guardGate();

	std::cout << std::string(50, '-') << std::endl;
	ScavTrap scav3(scav2);
	scav3.attack("Enemy3");
	scav3.takeDamage(40);
	scav3.beRepaired(30);
	scav3.guardGate();

	std::cout << std::string(50, '-') << std::endl;
	scav1 = scav2;
	scav1.attack("Enemy4");
	scav1.takeDamage(50);
	scav1.beRepaired(40);
	scav1.guardGate();
	return (0);
}
