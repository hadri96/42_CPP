/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:58:56 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 11:58:56 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <iomanip>

class HumanB
{
private:
	std::string	name;
	Weapon		*weapon;

public:
	HumanB();
	HumanB(std::string n);

	~HumanB();

	void	setWeapon(Weapon &weapon);
	void	attack(void);
};

#endif
