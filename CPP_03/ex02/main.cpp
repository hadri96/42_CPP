/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:56:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/24 14:56:52 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "Test Default Constructor" << std::endl;
	FragTrap frag1;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test Parameterized Constructor" << std::endl;
	FragTrap frag2("Fraggy");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test Copy Constructor" << std::endl;
	FragTrap frag3(frag2);
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test Copy Assignment Operator" << std::endl;
	frag1 = frag3;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test attack Function" << std::endl;
	frag2.attack("Target1");
	frag2.attack("Target2");
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test takeDamage Function" << std::endl;
	frag2.takeDamage(20);
	frag2.takeDamage(80);
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test beRepaired Function" << std::endl;
	frag2.beRepaired(50);
	frag2.beRepaired(50);
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Test highFivesGuys Function" << std::endl;
	frag2.highFivesGuys();
	std::cout << "--------------------------------" << std::endl;
	return 0;
}
