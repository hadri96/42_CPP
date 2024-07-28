/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:50:09 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:51:29 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	Weapon club_ = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club_);
	jim.attack();
	club_.setType("some other type of club");
	jim.attack();
	return 0;
}
